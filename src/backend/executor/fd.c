#include "postgres.h"
#include "executor/fd.h"

struct fd_list fd_info_list[10];
int i=0;
struct fd_list* end=NULL;
bool special_insert_into_fd_list=false;
// void init_fd_list_hard_code(){
// 	//hard-coding the values for testing purposes:: should not be used in final level::
// 	struct fd_struct* hc=malloc(sizeof(struct fd_struct));
// 	strcpy(hc->table_name,"delta_v5");
// 	hc->no_l_cols=1;
// 	hc->no_r_cols=1;
// 	hc->l_cols=malloc(hc->no_l_cols*sizeof(int));
// 	hc->r_cols=malloc(hc->no_r_cols*sizeof(int));
//     hc->l_cols[0]=1;
//     hc->r_cols[0]=2;
// 	fd_info_list=malloc(sizeof(struct fd_list));
// 	fd_info_list->next=NULL;
// 	fd_info_list->fd_info=hc;
// }

bool bool_to_check_fun_dep(struct fd_struct* curr,struct BITMAP* bitmap_obj,int16 *attr_nums,int num_attrs,char name[50]){

	   if(strcmp(name,curr->table_name)!=0){
		return false;
	   }
	   bool res=true;
	   for(int i=0;i<curr->no_l_cols;i++){
		 int idx=curr->l_cols[i]-1;
		 if(idx>=bitmap_obj->mx_attr || bitmap_obj->bitmap[idx]!='1'){
			res=false;
			return false;
		 }
	   }
	   
	   for(int i=0;i<curr->no_r_cols;i++){
		 int idx=curr->l_cols[i]-1;
		 if(idx>=bitmap_obj->mx_attr || bitmap_obj->bitmap[curr->r_cols[i]-1]!='1'){
			res=false;
			return res;
		 }
	   }

	  return res;


}

int find_att_num(int16 *attr_nums,int num_attr,int val){
    for(int i=0;i<num_attr;i++){
        if((int)attr_nums[i]==val){
            return i;
        }
    }
    return -1;
}

struct BITMAP* init_bitmap(int16 *attr_nums,int num_attrs){
    int mx_attr=-1;
	for(int i=0;i<num_attrs;i++){
		int num=(int)attr_nums[i];
		if(mx_attr<num){
			mx_attr=num;
		}
	}

	char* bitmap;
	bitmap=malloc(sizeof(char)*mx_attr);
	//init with 0's in the bitmap::
	for(int i=0;i<mx_attr;i++){
		bitmap[i]='0';
	}

	for(int i=0;i<num_attrs;i++){
		int num=(int)attr_nums[i];
		bitmap[num-1]='1';
	}
    struct BITMAP* bitmap_obj=malloc(sizeof(struct BITMAP));
    bitmap_obj->bitmap=bitmap;
	bitmap_obj->mx_attr=mx_attr;
	return bitmap_obj;
}




// int set_fd_list(struct fd_list *fd_info_list){
// 	if(fd_info_list==NULL){
// 		fd_info_list=malloc(sizeof(struct fd_list));
// 		end=fd_info_list;
// 	}
// 	end=fd_info_list;
//     return 1;
// }

bool insert_in_fd_list(struct fd_struct newfd){

	//struct fd_list *newfdlist=malloc(sizeof(struct fd_list));

	
	fd_info_list[i].fd_info=newfd;
	fd_info_list[i].next=NULL;
	if(i>0){
		fd_info_list[i-1].next=&fd_info_list[i];
	}
	i++;
	
	return true;
}
// void free_fun_dep_table(){
// 	//freeing all the memory generagted:
// 	struct fd_list* curr=fd_info_list;
// 	while(curr!=NULL){
// 		//allocated using palloc::
// 		//pfree(curr->fd_info);
// 		curr=curr->next;
// 		pfree(fd_info_list);
// 		fd_info_list=curr;
// 	}
	
// }




/* fd_struct which contains the information about the functional dependency*/

