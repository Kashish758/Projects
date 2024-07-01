#include<iostream>
#include<vector>
using namespace std;

class sets{
    vector<vector<int>> vectorofvectors;
    int size;
    public:
        sets(){
            size = 0;
        }

        int binarysearch(vector<int> *vec, int i){
            if (vec->size()==0){
                return 0;
            }
            else if (vec->size()==1){
                return 0;
            }
            
            else{
                int left = 0;
                int right = vec->size();
                int mid;
                while(left<right){
                    mid = (left + right)/2;
                    if ((*(vec))[mid]==i){
                        return mid;
                    }
                    else if ((*(vec))[mid]<i){
                        left = mid + 1;
                    }
                    else{
                        right = mid;
                    }
                }
                return left;
                }
            }

        void Insert(int set_num, int data){
            if(set_num>=size){
                for(int i = size;i<=set_num; i++){
                    vectorofvectors.push_back(vector<int>());
                }
            size = set_num + 1; 
            }
            vector<int>* vector_to_be_performed = &vectorofvectors[set_num];
            if (vector_to_be_performed->size()==0){
                vector_to_be_performed->push_back(data);
            }
            else if(vector_to_be_performed->size()==1){
                if ((*(vector_to_be_performed))[0]<data){
                    vector_to_be_performed->push_back(data);
                }
                else if ((*(vector_to_be_performed))[0]>data){
                    vector_to_be_performed->insert(vector_to_be_performed->begin(), data);
                }
            }
            else{
            int location_finder = binarysearch((vector_to_be_performed), data);

            if ((*(vector_to_be_performed))[location_finder] != data){
                vector_to_be_performed->insert(vector_to_be_performed->begin() + location_finder , data);
            }
            }
            cout<< vector_to_be_performed->size()<<endl;
        }

        void Print(int set_num){
            if(set_num>=size){
                cout<<endl; 
                return;
            }
            else{
                vector<int>* vector_to_be_performed = &vectorofvectors[set_num];
                if (vector_to_be_performed->size()==0){
                    cout<<endl;
                }
                else{
                    for(int i = 0; i<vector_to_be_performed->size()-1; i++){
                        cout<<(*(vector_to_be_performed))[i]<<",";
                    }
                    cout<<(*(vector_to_be_performed))[vector_to_be_performed->size() - 1]<<endl;
        }
        }
        }

        void Delete(int set_num, int data){
            vector<int>* vector_to_be_performed = &vectorofvectors[set_num];
            if(set_num>=size){
                cout<<-1<<endl;
                return;
            }
            else{
                int location_finder = binarysearch(vector_to_be_performed, data);
                if (vector_to_be_performed->size()==0){
                    cout<<0<<endl;
                    return;
                }
                else if (vector_to_be_performed->size()==1){
                    if ((*(vector_to_be_performed))[0]==data){
                        vector_to_be_performed->erase(vector_to_be_performed->begin());
                    }
                }
                else{
                    if ((*(vector_to_be_performed))[location_finder]==data){
                        vector_to_be_performed->erase(vector_to_be_performed->begin() + location_finder);
                    }
            }
            cout<<vector_to_be_performed->size()<<endl;
            }
        }

        void Belongs_to(int set_num, int data){
            if(set_num>=size){
                cout<<-1<<endl;
                return;
            }
            else{
                vector<int>* vector_to_be_performed = &vectorofvectors[set_num];
                int location_finder = binarysearch(vector_to_be_performed, data);
                if (vector_to_be_performed->size()==0){
                    cout<<0<<endl;
                }
                else{
                    if ((*(vector_to_be_performed))[location_finder]==data){
                        cout<< 1<<endl;
                    }
                    else{
                        cout<< 0<<endl;
                    }
            }
            }
        }

        void Union(int set_num_1, int set_num_2){
            int set_num;
            if (set_num_1>=set_num_2){
                set_num = set_num_1;
            }
            else{
                set_num = set_num_2;
            }
            if(set_num>=size){
                for(int i = size;i<=set_num; i++){
                    vectorofvectors.push_back(vector<int>());
                }
            size = set_num + 1;
            }
            vector<int>* vector_to_be_performed1 = &vectorofvectors[set_num_1];
            vector<int>* vector_to_be_performed2 = &vectorofvectors[set_num_2];
            vector<int> union_of_set1_set2;
            int i = 0, j = 0;
            while(i<vector_to_be_performed1->size() && j<vector_to_be_performed2->size()){
                if ((*(vector_to_be_performed1))[i]<(*(vector_to_be_performed2))[j]){
                    union_of_set1_set2.push_back((*(vector_to_be_performed1))[i]);
                    i++;
                }
                else if((*(vector_to_be_performed1))[i]==(*(vector_to_be_performed2))[j]){
                    union_of_set1_set2.push_back((*(vector_to_be_performed1))[i]);
                    i++;
                    j++;
                }
                else{
                    union_of_set1_set2.push_back((*(vector_to_be_performed2))[j]);
                    j++;
                }
            }
            while(i<vector_to_be_performed1->size()){
                union_of_set1_set2.push_back((*(vector_to_be_performed1))[i]);
                i++;
            }
            while(j<vector_to_be_performed2->size()){
                union_of_set1_set2.push_back((*(vector_to_be_performed2))[j]);
                j++;
            }
            vectorofvectors[set_num_1] = union_of_set1_set2;
            cout<<vectorofvectors[set_num_1].size()<<endl;
        }

        void Size(int set_num){
            if(set_num>=size){
                for(int i = size;i<=set_num; i++){
                    vectorofvectors.push_back(vector<int>());
                }
            size = set_num + 1; 
            }
            vector<int>* vector_to_be_performed = &vectorofvectors[set_num];
            cout<<vector_to_be_performed->size()<<endl;
        }

        void Difference(int set_num_1, int set_num_2){
            int set_num;
            if (set_num_1>=set_num_2){
                set_num = set_num_1;
            }
            else{
                set_num = set_num_2;
            }
            if(set_num>=size){
                for(int i = size;i<=set_num; i++){
                    vectorofvectors.push_back(vector<int>());
                }
            size = set_num + 1; 
            }
            vector<int>* vector_to_be_performed1 = &vectorofvectors[set_num_1];
            vector<int>* vector_to_be_performed2 = &vectorofvectors[set_num_2];
            vector<int> difference_of_set1_set2;
            int i = 0, j = 0;
            while(i<vector_to_be_performed1->size() && j<vector_to_be_performed2->size()){
                if ((*(vector_to_be_performed1))[i]==(*(vector_to_be_performed2))[j]){
                    i++;
                    j++;
                }
                else if ((*(vector_to_be_performed1))[i]>(*(vector_to_be_performed2))[j]){
                    j++;
                }
                else{
                    difference_of_set1_set2.push_back((*(vector_to_be_performed1))[i]);
                    i++;
                }
            }
            while(i<vector_to_be_performed1->size()){
                difference_of_set1_set2.push_back((*(vector_to_be_performed1))[i]);
                i++;
            }
            vectorofvectors[set_num_1] = difference_of_set1_set2;
            cout<<vectorofvectors[set_num_1].size()<<endl;
        }

        void Intersection(int set_num_1, int set_num_2){
            int set_num;
            if (set_num_1>=set_num_2){
                set_num = set_num_1;
            }
            else{
                set_num = set_num_2;
            }
            if(set_num>=size){
                for(int i = size;i<=set_num; i++){
                    vectorofvectors.push_back(vector<int>());
                }
            size = set_num + 1; 
            }
            vector<int>* vector_to_be_performed1 = &vectorofvectors[set_num_1];
            vector<int>* vector_to_be_performed2 = &vectorofvectors[set_num_2];
            vector<int> intersection_of_set1_set2;
            int i = 0, j = 0;
            while(i<vector_to_be_performed1->size() && j<vector_to_be_performed2->size()){
                if ((*(vector_to_be_performed1))[i]<(*(vector_to_be_performed2))[j]){
                    i++;
                }
                else if((*(vector_to_be_performed1))[i]==(*(vector_to_be_performed2))[j]){
                    intersection_of_set1_set2.push_back((*(vector_to_be_performed1))[i]);
                    i = i + 1;
                    j = j + 1;
                }
                else{
                    j++;
                }
            }
            vectorofvectors[set_num_1] = intersection_of_set1_set2; 
            cout<<intersection_of_set1_set2.size()<<endl; 
        }

        void Symmetric_Difference(int set_num_1, int set_num_2){
            int set_num;
            if (set_num_1>=set_num_2){
                set_num = set_num_1;
            }
            else{
                set_num = set_num_2;
            }
            if(set_num>=size){
                for(int i = size;i<=set_num; i++){
                    vectorofvectors.push_back(vector<int>());
                }
            size = set_num + 1; 
            }
            vector<int>* vector_to_be_performed1 = &vectorofvectors[set_num_1];
            vector<int>* vector_to_be_performed2 = &vectorofvectors[set_num_2];
            vector<int> difference_of_union_and_intersection;
            int i = 0, j = 0;
            while(i<vector_to_be_performed1->size() && j<vector_to_be_performed2->size()){
                if ((*(vector_to_be_performed1))[i]<(*(vector_to_be_performed2))[j]){
                    difference_of_union_and_intersection.push_back((*(vector_to_be_performed1))[i]);
                    i++;
                }
                else if((*(vector_to_be_performed1))[i]>(*(vector_to_be_performed2))[j]){
                    difference_of_union_and_intersection.push_back((*(vector_to_be_performed2))[j]);
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
            while(i<vector_to_be_performed1->size()){
                difference_of_union_and_intersection.push_back((*(vector_to_be_performed1))[i]);
                i++;
            }
            while(j<vector_to_be_performed2->size()){
                difference_of_union_and_intersection.push_back((*(vector_to_be_performed2))[j]);
                j++;
            }
            vectorofvectors[set_num_1] = difference_of_union_and_intersection;
            cout<<vectorofvectors[set_num_1].size()<<endl;
        }

        void coderunner(int i){

            if(i==1){
                int j,k;
                cin>>j>>k;
                Insert(j,k);
            }

            else if (i==2){
                int j,k;
                cin>>j>>k;
                Delete(j,k);
            }

            else if (i==3){
                int j,k;
                cin>>j>>k;
                Belongs_to(j,k);
            }

            else if (i==4){
                int j,k;
                cin>>j>>k;
                Union(j,k);
            }

            else if (i==5){
                int j,k;
                cin>>j>>k;
                Intersection(j,k);
            }

            else if (i==6){
                int j;
                cin>>j;
                Size(j);
            }

            else if (i==7){
                int j,k;
                cin>>j>>k;
                Difference(j,k);
            }

            else if (i==8){
                int j,k;
                cin>>j>>k;
                Symmetric_Difference(j,k);
            }

            else if (i==9){
                int j;
                cin>>j;
                Print(j);
            }
        }
};

int main(){
    sets S;
    int i;
    while(cin>>i){
        S.coderunner(i);
    }
    return 0;
}