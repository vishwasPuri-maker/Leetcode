class Solution {
    public boolean isAnagram(String s, String t) {
        char[] c = s.toCharArray();
        char[] ss = t.toCharArray();
        if(c.length != ss.length){
            return false;
        }
        Arrays.sort(c);
        Arrays.sort(ss);
        return Arrays.equals(c,ss);
    }
}