class Solution {
    public int lengthOfLastWord(String s) {
        int l=s.length();
        String [] w=s.split(" ");
        String lastword=w[w.length -1];
        int lenLast=lastword.length();
        return lenLast;
    }
}