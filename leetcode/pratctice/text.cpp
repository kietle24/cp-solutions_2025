class Solution { 
     public :  
     vector<double> averageOfLevels(TreeNode* root) {  
        if(!root) return {}  ; 
        queue<TreeNode*> q ;
            q.push(root) ; 
        vector<double> res; 
        while(!q.empty()) { 
            double count  = q.size()  ; 
            long long sum = 0 ; 
            for(int i =0  ; i  < count ; i++) {  
                TreeNode* node = q.front()  ; 
                q.pop()  ;
                sum += node->val ; 
                if(node ->left ) q.push(node->left ) ; 
                if(node -> right ) q.push(node->right ) ; 
                
         
            }
            res.push_back(double sum / count) ; 
        } 
        return res ; 
     }
};  