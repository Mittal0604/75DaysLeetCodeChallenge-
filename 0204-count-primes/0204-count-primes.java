class Solution {
    static int[] count;
    public int countPrimes(int n) {
        if (n<2) return 0;
        if (count == null) {
            int max = 5000000;
            count = new int[max+1];
            int[] arr = new int[max];
            Arrays.fill(arr,1);
            arr[0] = arr[1] = 0;
            for (int i = 2;i*i<max;i++) {
                if (arr[i] == 0) continue;
                for (int j = i*i;j<max;j+=i) {
                    arr[j] = 0;
                }
            }
            Arrays.fill(count,0);
            for (int i = 1;i<max;i++) {
                count[i] = count[i-1] + arr[i];
            }
        }
        return count[n-1];
    }
}