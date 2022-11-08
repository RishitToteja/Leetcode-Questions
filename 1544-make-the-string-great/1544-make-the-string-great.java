class Solution {
    public String makeGood(String s) {
        boolean temp = true;
        while(temp){
            String n = "";
            boolean bol = false;
            temp = false;
            for(int i=0; i<s.length()-1; i++){
                if((s.charAt(i)>='a' && s.charAt(i)<='z') && s.charAt(i+1)==(s.charAt(i)-32)){
                    temp = true;
                    if(i==s.length()-2){
                        bol = true;
                        
                    }
                    i++;
                }
                else if((s.charAt(i)>='A' && s.charAt(i)<='Z') && s.charAt(i+1)==(s.charAt(i)+32)){
                    temp = true;
                    if(i==s.length()-2){
                        bol = true;
                    }
                    i++;

                }
                else
                    n += s.charAt(i);
            }
            if(!bol && s.length()!=0)
                n+= s.charAt(s.length()-1);
            s = n;
        }
        
        return s;
    }
}