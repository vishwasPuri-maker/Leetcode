class Solution {
    public String mergeAlternately(String word1, String word2) {
        char[] a = word1.toCharArray();
        char[] b = word2.toCharArray();
        int i = 0;
        int j = 0;

        StringBuilder sb = new StringBuilder();
        while (i < a.length || j < b.length) {
            if (i < a.length) {
                sb.append(a[i]);
                i++;
            }
            if (j < b.length) {
                sb.append(b[j]);
                j++;
            }
        }
        return sb.toString();
    }
}