class Solution { 
      public : 
      vector<double> averageOfLevels(TreeNode* root) {
          
            queue<TreeNode* > q ; 
            q.push(root) ;
             vector<double > result ; 
            while(!q.empty()) {  
                double sum = 0 ; 
                int count  = q.size() ; 
                for(int i =0 ; i < count ;i++){ 
                    TreeNode* node = q.front() ; 
                    q.pop() ; 
                    sum += node->val ; 
                    if(node->left != nullptr) { 
                         q.push(node->left) ; 
                    }
                    if(node->right != nullptr) { 
                         q.push(node->right) ; 
                    }
                }
                result.push_back(sum / count) ;
            }
           
            return result ;
        }
};

