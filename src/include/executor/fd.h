#ifndef FUNDEP_H
#define FUNDEP_H
struct fd_struct{
	char table_name[50];
	int no_l_cols;
	int no_r_cols;
	int l_cols[10];
	int r_cols[10];
};

struct fd_list{
	struct fd_struct fd_info;
	struct fd_list *next;
};

extern struct fd_list fd_info_list[10];
extern struct fd_list *end;
extern int i;
extern void init_fd_list_hard_code();
struct BITMAP{
	char* bitmap;
	int mx_attr;
};
extern struct BITMAP* init_bitmap(int16 *attr_nums,int num_attrs);
extern bool bool_to_check_fun_dep(struct fd_struct* curr,struct BITMAP* bitmap_obj,int16 *attr_nums,int num_attrs,char name[50]);

struct name{
    char table_name[50];
};



// int set_fd_list(struct fd_list *fd_info_list){
// 	if(fd_info_list==NULL){
// 		fd_info_list=malloc(sizeof(struct fd_list));
// 		end=fd_info_list;
// 	}
// 	end=fd_info_list;
//     return 1;
// }
extern int find_att_num(int16 *attr_nums,int num_attr,int val);
extern bool insert_in_fd_list(struct fd_struct newfd);

extern bool special_insert_into_fd_list;
#endif