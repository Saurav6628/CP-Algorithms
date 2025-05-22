class sqrtDec{
    vector<long long> sroot; // Stores the increment for each block (lazy update)
    int eleN;                // Number of elements per block (block size)
    int boxN;                // Number of blocks
    int N;                   // Total number of elements in the array
    vector<long long> data;  // Stores the actual data values
    public:
    
    // Constructor to initialize the sqrtDec object with nums array
    sqrtDec(vector<int> &nums)
    {
        N=nums.size();               // Get the size of the input array
        eleN=int(sqrt(N));           // Set block size to sqrt(N)
        boxN=(N/eleN)+2;             // Calculate number of blocks (+2 for safety)
        sroot.assign(boxN,0);        // Initialize all block increments to 0
        data.assign(nums.begin(),nums.end()); // Copy input values into data vector
    }

    // Query function to get the value at index i after all updates
    long long query(int i) {
        // Return the actual value plus any increment from its block
        return data[i]+sroot[int(i/eleN)];
    }

    // Range update: add 'val' to all elements from index l to r (inclusive)
    void update(int l, int r, int val)
    {
        int boxr=int(r/eleN); // Get block index for r
        
        // Update elements in the partial left block individually
        while (l<=r and ((l-1)/eleN)==(l/eleN)) data[l++]+=val;
        
        // Update complete blocks fully contained within [l, r] by lazy increment
        while (l<=r and int(l/eleN)!=boxr)
        {
            sroot[int(l/eleN)]+=val;
            l+=eleN; // Move to next block
        }
        // Update elements in the partial right block individually
        while (l<=r) data[l++]+=val;
        return;
    }
};
