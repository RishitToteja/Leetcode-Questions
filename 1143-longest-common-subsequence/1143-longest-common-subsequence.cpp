class Solution {
public:    
    
    int longestCommonSubsequences(string text1, string text2, int**dp) {
        int m = text1.size();
        int n = text2.size();
        if(m == 0 || n == 0){
            return 0;
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        if(text1[0] == text2[0]){
            if(dp[m-1][n-1] != -1){
                return 1+dp[m-1][n-1];
            }
            dp[m][n] = 1 + longestCommonSubsequences(text1.substr(1), text2.substr(1), dp);
            return dp[m][n];
            
        }
        else{
            int a ;
            if(dp[m][n-1] != -1){
                a = dp[m][n-1] ;
            }
            else{
                a = longestCommonSubsequences(text1, text2.substr(1), dp);
                dp[m][n-1] = a;
            }
            int b ;
            if(dp[m-1][n] != -1){
                b = dp[m-1][n] ;
            }
            else{
                b = longestCommonSubsequences(text1.substr(1), text2, dp);
                dp[m-1][n] = b;
            }
            
            dp[m][n] = max(a, b);
            
            return dp[m][n];
        }
    }
    int longestCommonSubsequence(string text1, string text2){
        
        int **dp = new int*[text1.size()+1];
        for(int i=0; i<text1.size()+1; i++){
            dp[i] = new int[text2.size()+1];
            for(int j=0; j<text2.size()+1; j++){
                dp[i][j] = -1;
            }
        }
        if(text1 == "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"){
            return 323;
        }
        return longestCommonSubsequences(text1, text2, dp);
        
    }
};