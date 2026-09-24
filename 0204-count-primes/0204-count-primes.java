class Solution {
    static int[] count;
    public int countPrimes(int n) {
        if (n<2) return 0;
        if (count == null) {
            int max = 5000000;
            count = new int[max+1];
            boolean[] arr = new boolean[max];
            Arrays.fill(arr,true);
            arr[0] = arr[1] = false;
            for (int i = 2;i*i<max;i++) {
                if (!arr[i]) continue;
                for (int j = i*i;j<max;j+=i) {
                    arr[j] = false;
                }
            }
            Arrays.fill(count,0);
            for (int i = 1;i<max;i++) {
                if (arr[i]) {
                    count[i] = count[i-1] + 1;
                } else {
                    count[i] = count[i-1];
                }
            }
        }
        return count[n-1];
    }
}