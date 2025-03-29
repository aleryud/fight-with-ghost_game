#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<windows.h>

//语言文本
#define Part0_E "choose you language,please"
#define Part0_C "请选择你的语言"
#define Part0_J "言語を選択してください"
#define Part0_R "Пожалуйста, выберите язык"
#define Part0_F "Veuillez choisir votre langue, s'il vous plaît"
#define Part0_Q ""
#define Part0_M_C ""
#define Part0_M_J ""

#define Part1_E "English[0]"
#define Part1_C "中文[1]"
#define Part1_R ""
#define Part1_F ""
#define Part1_Q ""
#define Part1_M_C ""
#define Part1_M_J ""


#define Part2_E "Please press right command for you need "
#define Part2_C "请按指示再次输入，不要瞎输"

#define Part3_E "This is game map,you are the'W'and the'G'is ghost"
#define Part3_C "下面是游戏地图，其中“W”为你的位置，“G”为鬼魂的位置"


#define Part4_E "Everyone can move or do some thing by one round"
#define Part4_C "各单位每回合均可十字方向移动一格或执行一次其他行为"


#define Part5_E "Who first touch others can kill him"
#define Part5_C "先踩到对方就能将其消灭，反之亦然"


#define Part6_E "you just can see ghost when ther near you and be careful their shoot"
#define Part6_C "另外你只有在鬼魂附近才能看到他们，哦，还有小心他们发出的寒气。"


#define Part7_E "You can move when enter a right command or long right command,if you want"
#define Part7_C "你可以按如下的指示移动，另外你还可以输入连续指令一次性移动，呵呵，如果你想的话"


#define Part8_E "upward[W] downward[S] left[A] right[D] stay[K]"
#define Part8_C "向上[W] 向下[S] 向左[A] 向右[D] 停留[K]"


#define Part9_E "there haven't road,boy"
#define Part9_C "这边走不了哦，骚年"


#define Part10_E "‘W’-- You,kill all ghost for victory"
#define Part10_C "“W”—— 你，消灭所有幽灵就能胜利"


#define Part11_E " 'G' -- The ghost ,have two(in normal difficulty),just can be find when they around you"
#define Part11_C "“G”—— 幽灵，有两只（除非你设置了别的难度），只有在你周围八格时才能被看到"


#define Part12_E "‘*’-- The cold from ghost,just move on straight line(just be find around you too),if you catch it will be frozen"
#define Part12_C "“*”—— 幽灵发出的寒气，只会朝一定方向直线移动，当你触碰到时会被冻住一回合，同样只有在周围八格才能被发现"


#define Part13_E "The distance(in you 'n'th outward circle) by one of ghost:"
#define Part13_C "其中一个随机幽灵与你的距离（以你为中心向外的第n圈）为："


#define Part14_E "You are win"
#define Part14_C "你赢了"


#define Part15_E "Oh,you die"
#define Part15_C "吼，死了啦"


#define Part16_E "You just complete rounds is:"
#define Part16_C "这是你刚刚进行的回合数："


#define Part17_E "How do you feel? Do you want play again?"
#define Part17_C "感觉怎样？还要再玩一次吗"


#define Part18_E "again[0]   no,quit[1]   no,but I want to chat with you[2]"
#define Part18_C "再来一次吧[0]  不了，退出[1]  不了，但是我想和你聊聊[2]"


#define Part19_E "It`s wrong instruction"
#define Part19_C "你输错了，看好再输吧"


#define Part20_E "Can you enter right instruction?"
#define Part20_C "额，都最后了好好按指示输行不"


#define Part21_E "You did in intentionally,right"
#define Part21_C "你故意的吧"


#define Part22_E "......"
#define Part22_C "。。。。。。"


#define Part23_E "FUCK YOU"
#define Part23_C "去你的"


#define Part24_E ""
#define Part24_C ""


#define Part25_E ""
#define Part25_C ""


#define Part26_E ""
#define Part26_C ""


#define Part27_E "What are you fuck play"
#define Part27_C "去你的，别玩了"


#define Part28_E ""
#define Part28_C ""


#define Part29_E ""
#define Part29_C ""


#define Part30_E ""
#define Part30_C ""


#define Part31_E ""
#define Part31_C ""



/*void lanuage_cont() {
	const char* Part1_E = "choose you language please"
}

struct {
	char part_1;
	char part_2;
	char part_3;
	char part_4;
   }lanuage_choose[2]{1,2};//中文,英文

   static void lanuage() {
	   lanuage_choose.part_1 =  Part1_C ;
   }
		*/

		//权举，便于管理数值
enum {
	//map
	empty = 0,
	human = 1,
	human_keep = 2,
	ghost_1 = 3,
	ghost_1_no_visual = 4,
	ghost_2 = 5,
	ghost_2_no_visual = 6,
	num_all_thing = 10,
	//language
	lanuage_number = 8
};

//结构体，对应135行的坐标补丁
struct {
	int con[6];
}part_sit[6];

//地图区域划分
struct {
	int con[4];
}map_area[9];

//文本语言存储（对应的语言，对应的文本）
const char* lanuage_choose(int a, int b) {
	const char* lanuage_con[lanuage_number][50]{
		{Part0_E,Part1_E,Part2_E,Part3_E ,Part4_E,Part5_E,Part6_E,Part7_E,Part8_E,Part9_E,Part10_E,Part11_E,Part12_E,Part13_E,Part14_E,Part15_E,Part16_E,Part17_E,Part18_E,Part19_E,Part20_E,Part21_E,Part22_E,Part23_E,Part24_E,Part25_E,Part26_E,Part27_E,Part28_E,Part29_E,Part30_E},
		{Part0_C,Part1_C,Part2_C,Part3_C ,Part4_C,Part5_C,Part6_C,Part7_C,Part8_C,Part9_C,Part10_C,Part11_C,Part12_C,Part13_C,Part14_C,Part15_C,Part16_C,Part17_C,Part18_C,Part19_C,Part20_C,Part21_C,Part22_C,Part23_C,Part24_C,Part25_C,Part26_C,Part27_C,Part28_C,Part29_C,Part30_C},
	};
	return lanuage_con[a][b];
}

//文本颜色
void color(int color);
//随机数（随机数的范围）
int random(int limit);
//随机数库检验（读取随机数数组，读取位置，位置链接，检测模式（0：初始化；1：避开现有位置））（使库中的各数不重复）
int random_test(int* ran, int* sit, int i, int check_mode);
//随机数库（读取随机数数组，读取位置，需求模式(0:初始；1：避开现有位置)）
void random_con(int* ran, int* sit, int check_mode);
//人物填充（数组，调用随机数数组确定初位置，单位种类）
void entity(int* sit, int entity_sit, int type);
//坐标系设置
void sit_patch();
//单位x或y的坐标值（单位位置，提供x或y）
int coor_x_or_y(int unit_sit, char x_or_y);
//两单位间x或y的距离（单位1的位置，单位2的位置，提供x或y）
int distance_x_or_y(int unit_1, int unit_2, char x_or_y);
//结果判断
int end(bool play, bool ghost1, bool ghost2);
//所有单位的状态处理
void unit_status(int* sit, bool* play_p, bool* ghost1_p, bool* ghost2_p);
//任意一幽灵与玩家的距离
int ran_ghost_dis(int* sit, bool play, bool ghost1, bool ghost2);
//地图打印
void map_print(int* sit);
//人物位置控制
void player_sit(int* sit, int lanuage);
//地图区域划分，便于ai（这个ai是指怪物行动逻辑）逻辑控制
void area();
//地图位置区域返回
int area_return(int* sit, int unit);
//怪物位置控制(ai)(独立行动)
void ghost_move(int* sit, int ghost);
//道具

//聊天
void chat();
//成就1
void achievement_1(int lanuage, int bugger, int part);


//主程序
int main() {
	int lanuage = 0, bugger = 0, repeat = 0, round = 0, input;
	bool play = true, ghost1 = true, ghost2 = true;//单位状态
	bool* play_p = &play, * ghost1_p = &ghost1, * ghost2_p = &ghost2;//单位状态的指针
	int sit[36]{ 0 }, ran[num_all_thing + 1]{ 0 };//sit用于存储单位的地图位置，ran则是不重复的随机数段
	const int red = 4, green = 2, blue = 1;//字体颜色
	srand(time(NULL));//随机数种子设置

	//内存分配（改为静态指针了，所以不需要了）
	//for (int i = 0; i <= 35;i++) {
		//sit[i] = (int*)malloc(sizeof(int));
	//}
	//for (int i = 0; i <= num_all_thing; i++) {
		//ran[i] = (int*)malloc(sizeof(int));
	//}

	//文本语种选择部分
	for (int i = 0; i < lanuage_number; i++) {
		printf("%s\n%s\n\n", lanuage_choose(lanuage, 0), lanuage_choose(lanuage, 1));
		lanuage++;
	}
	printf(">>>");
	while (1) {
		scanf_s("%d", &lanuage);
		if (lanuage == 0 || lanuage == 1) {
			break;
		}
		else if (bugger >= 3) {
			lanuage = 0;
			for (int i = 0; i < lanuage_number; i++) {
				printf("%s\n", lanuage_choose(lanuage, 27));
				lanuage++;
			}return 0;
		}
		else {
			while (getchar() != '\n');
			lanuage = 0;
			for (int i = 0; i < lanuage_number; i++) {
				printf("%s\n%s\n\n", lanuage_choose(lanuage, 2), lanuage_choose(lanuage, 1));
				lanuage++;
			}
			printf(">>>");
			bugger++;//你猜这是干什么的
		}
	}
	//游戏部分
	printf("%s\n%s\n%s\n%s\n", lanuage_choose(lanuage, 3), lanuage_choose(lanuage, 4), lanuage_choose(lanuage, 5), lanuage_choose(lanuage, 6));//游戏介绍
	sit_patch();
	area();
	//scanf_s("%d",&input);
	//if (input==1) {
	while (1) {
		round = 0;
		input = -1;
		play = true;
		ghost1 = true;
		ghost2 = true;
		//初始化数组
		for (int i = 0; i <= 35; i++)
		{
			entity(sit, i, empty);
		}
		for (int i = 0; i <= num_all_thing; i++)
		{
			ran[i] = 40;
		}
		//建立随机数数库
		random_con(ran, sit, 0);
		//地图单位初设置
		entity(sit, ran[0], human);
		entity(sit, ran[1], ghost_1);
		entity(sit, ran[2], ghost_2);
		//for (int i=0; i <= num_all_thing;i++) {
		//	free(ran[i]);  原定的内存释放，同样不需要了
		//}
		while (1) {//主要的游戏运行部分
			unit_status(sit, play_p, ghost1_p, ghost2_p);
			map_print(sit);//地图打印
			//结束判断
			if (end(play, ghost1, ghost2) == 0) {
				printf("\n%s\n", lanuage_choose(lanuage, 14));
				break;
			}
			else if (end(play, ghost1, ghost2) == 1) {
				printf("\n%s\n", lanuage_choose(lanuage, 15));
				break;
			}
			//地图符号介绍
			printf("%s\n%s\n%s\n\n", lanuage_choose(lanuage, 10), lanuage_choose(lanuage, 11), lanuage_choose(lanuage, 12));
			//随机幽灵位置报告
			printf("%s%d\n\n", lanuage_choose(lanuage, 13), ran_ghost_dis(sit, play, ghost1, ghost2));
			//输入指示
			printf("%s\n", lanuage_choose(lanuage, 7));
			//输入指令
			player_sit(sit, lanuage);
			//怪物行动
			if (ghost1) {
				ghost_move(sit, ghost_1);
			}
			if (ghost2) {
				ghost_move(sit, ghost_2);
			}
			round++;
		}
		printf("%s%d\n\n%s\n\n%s\n", lanuage_choose(lanuage, 16), round, lanuage_choose(lanuage, 17), lanuage_choose(lanuage, 18));
		bugger = 0;
		while (1) {
			printf(">>>");
			//while (getchar() != '\n')
			scanf_s("%d", &input);
			if (input == 0) {
				break;
			}
			else if (input == 1) {
				return 0;
			}
			else if (input == 2) {
				chat;
			}
			else {
				while (getchar() != '\n');
				bugger++;
			}
			achievement_1(lanuage, bugger, 1);
			if (bugger == 5) {
				return 0;
			}
			printf("%s\n", lanuage_choose(lanuage, 18));
		}
		continue;
	}
	//}
	/*else {//这里是为便于测试编写的部分，不用在意
		for (int n = 0; n <= 8;n++) {
			printf("\n");
			for (int i = 0; i <= 3;i++) {
				printf("%d",map_area[n].con[i]);
			}

		}
	}*/
}


//文本颜色
void color(int color) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
}

//随机数（随机数的范围）
int random(int limit) {
	int a;
	a = rand() % limit;
	return a;
}

//随机数库检验（读取随机数数组，读取位置，位置链接，检测模式（0：初始化；1：避开现有位置））（使库中的各数不重复）
int random_test(int* ran, int* sit, int i, int check_mode) {
	for (int n = 0; n <= num_all_thing; n++) {
		if (n != i && ran[i] == ran[n]) {
			return 1;
		}
		if (check_mode == 0) {
			if (ran[i] - 1 == ran[n] || ran[i] + 1 == ran[n] || ran[i] + 6 == ran[n] || ran[i] - 6 == ran[n]) {
				return 1;
			}
		}
		else if (check_mode == 1) {
			if (sit[ran[i]] != 0) {
				return 1;
			}
		}
	}return 0;
}

//随机数库（读取随机数数组，读取位置，需求模式(0:初始；1：避开现有位置)）
void random_con(int* ran, int* sit, int check_mode) {
	for (int i = 0; i <= num_all_thing; i++) {
		ran[i] = random(36);
		if (random_test(ran, sit, i, check_mode) == 1) {
			i--;
		}
	}
}

//人物填充（数组，调用随机数数组确定初位置，单位种类）
void entity(int* sit, int entity_sit, int type) {
	sit[entity_sit] = type;
}

//坐标系设置
void sit_patch() {
	for (int i = 0; i <= 5; i++) {
		for (int n = 0, m = 0; n <= 5; n++, m += 6)
		{
			part_sit[i].con[n] = m + i;
		}
	}
}

//单位x或y的坐标值（单位位置，提供x或y）
int coor_x_or_y(int unit_sit, char x_or_y) {
	int save_1_x = -1, save_1_y = -1;
	for (int i = 0; i <= 5; i++) {
		for (int n = 0; n <= 5; n++)
		{
			if (part_sit[i].con[n] == unit_sit) {
				save_1_x = i;
				save_1_y = n;
			}
		}
	}
	if (x_or_y == 'x')
	{
		return save_1_x;
	}
	else if (x_or_y == 'y') {
		return save_1_y;
	}
}

//两单位间x或y的距离（单位1的位置，单位2的位置，提供x或y）
int distance_x_or_y(int unit_1, int unit_2, char x_or_y) {
	int x_dis, y_dis;
	x_dis = abs(coor_x_or_y(unit_1, 'x') - coor_x_or_y(unit_2, 'x'));
	y_dis = abs(coor_x_or_y(unit_1, 'y') - coor_x_or_y(unit_2, 'y'));
	if (x_or_y == 'x') {
		// printf("%d",x_dis);
		return x_dis;
	}
	else if (x_or_y == 'y') {
		// printf("%d", y_dis);
		return y_dis;
	}
}

//结果判断
int end(bool play, bool ghost1, bool ghost2) {
	if (play && !ghost1 && !ghost2) {
		return 0;
	}
	else if (!play) {
		return 1;
	}
	else {
		return 2;
	}
}

//所有单位的状态处理
void unit_status(int* sit, bool* play_p, bool* ghost1_p, bool* ghost2_p) {
	int g_1_sit = 40, g_2_sit = 40, p_sit = 40;
	for (int i = 0; i <= 35; i++) {
		if (sit[i] == ghost_1 || sit[i] == ghost_1_no_visual) {
			g_1_sit = i;
		}
		if (sit[i] == ghost_2 || sit[i] == ghost_2_no_visual) {
			g_2_sit = i;
		}
		if (sit[i] == human || sit[i] == human_keep) {
			p_sit = i;
		}
	}
	if (p_sit == 40) {
		*play_p = false;
	}
	if (g_1_sit == 40) {
		*ghost1_p = false;
	}
	if (g_2_sit == 40) {
		*ghost2_p = false;
	}
	if (p_sit != 40) {
		if (g_1_sit != 40 && g_2_sit != 40) {
			if (distance_x_or_y(p_sit, g_1_sit, 'x') <= 1 && distance_x_or_y(p_sit, g_1_sit, 'y') <= 1) {
				sit[g_1_sit] = ghost_1_no_visual;
			}
			else {
				sit[g_1_sit] = ghost_1;
			}
			if (distance_x_or_y(p_sit, g_2_sit, 'x') <= 1 && distance_x_or_y(p_sit, g_2_sit, 'y') <= 1) {
				sit[g_2_sit] = ghost_2_no_visual;
			}
			else {
				sit[g_2_sit] = ghost_2;
			}
		}
		else if (g_1_sit != 40 && g_2_sit == 40) {
			if (distance_x_or_y(p_sit, g_1_sit, 'x') <= 1 && distance_x_or_y(p_sit, g_1_sit, 'y') <= 1) {
				sit[g_1_sit] = ghost_1_no_visual;
			}
			else {
				sit[g_1_sit] = ghost_1;
			}
		}
		else if (g_1_sit == 40 && g_2_sit != 40) {
			if (distance_x_or_y(p_sit, g_2_sit, 'x') <= 1 && distance_x_or_y(p_sit, g_2_sit, 'y') <= 1) {
				sit[g_2_sit] = ghost_2_no_visual;
			}
			else {
				sit[g_2_sit] = ghost_2;
			}
		}
	}
	else {
		sit[g_1_sit] = ghost_1;
		sit[g_2_sit] = ghost_2;
	}
}

//任意一幽灵与玩家的距离
int ran_ghost_dis(int* sit, bool play, bool ghost1, bool ghost2) {
	int g_1_sit, g_2_sit, p_sit;
	if (play && ghost1 || ghost2) {
		for (int i = 0; i <= 35; i++) {
			if (ghost1 && sit[i] == ghost_1 || sit[i] == ghost_1_no_visual) {
				g_1_sit = i;
			}
			if (ghost2 && sit[i] == ghost_2 || sit[i] == ghost_2_no_visual) {
				g_2_sit = i;
			}
			if (sit[i] == human || sit[i] == human_keep) {
				p_sit = i;
			}
		}
		if (ghost1 && ghost2) {
			if (random(2) == 1) {
				return max(distance_x_or_y(g_1_sit, p_sit, 'x'), distance_x_or_y(g_1_sit, p_sit, 'y'));
			}
			else {
				return max(distance_x_or_y(g_2_sit, p_sit, 'x'), distance_x_or_y(g_2_sit, p_sit, 'y'));
			}
		}
		else {
			if (ghost1) {
				return max(distance_x_or_y(g_1_sit, p_sit, 'x'), distance_x_or_y(g_1_sit, p_sit, 'y'));
			}
			else {
				return max(distance_x_or_y(g_2_sit, p_sit, 'x'), distance_x_or_y(g_2_sit, p_sit, 'y'));
			}
		}
	}
}


//地图打印
void map_print(int* sit) {
	int n = 0, m = 5;
	for (int i = 1; i <= 6; i++, m += 6) {
		printf("\n+---+---+---+---+---+---+\n|");
		for (n; n <= m; n++) {
			switch (sit[n])
			{
			case empty:
				printf("   |");
				break;
			case human:
				printf(" W |");
				break;
			case human_keep:
				color(1);
				printf(" W ");
				color(7);
				printf("|");
				break;
			case ghost_1:
				printf(" G |");
				break;
			case ghost_1_no_visual:
				color(4);
				printf(" G |");
				color(7);
				break;
			case ghost_2:
				printf(" G |");
				break;
			case ghost_2_no_visual:
				color(4);
				printf(" G |");
				color(7);
				break;
			}
		}
	}printf("\n+---+---+---+---+---+---+\n");

}

//人物位置控制
void player_sit(int* sit, int lanuage) {
	int p_sit = 40, i = 0;
	char input;
	for (i; i <= 35; i++)
	{
		if (sit[i] == human) {
			p_sit = i;
			break;
		}
	}
	if (p_sit == 40) {

	}
	else {
		printf("%s\n", lanuage_choose(lanuage, 8));
		while (1) {
			printf(">>>");
			scanf_s(" %c", &input);
			if (input == 'W' || input == 'w') {
				if (p_sit >= 0 && p_sit <= 5) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_sit -= 6;
					break;
				}
			}
			else if (input == 'S' || input == 's') {
				if (p_sit >= 30 && p_sit <= 35) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_sit += 6;
					break;
				}
			}
			else if (input == 'A' || input == 'a') {
				if (p_sit == 0 || p_sit == 6 || p_sit == 12 || p_sit == 18 || p_sit == 24 || p_sit == 30) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_sit--;
					break;
				}
			}
			else if (input == 'D' || input == 'd') {
				if (p_sit == 5 || p_sit == 11 || p_sit == 17 || p_sit == 23 || p_sit == 29 || p_sit == 35) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_sit++;
					break;
				}
			}
			else if (input == 'K' || input == 'k') {
				break;
			}
			else {
				printf("%s\n", lanuage_choose(lanuage, 2));
			}
		}
		entity(sit, i, empty);
		entity(sit, p_sit, human);
	}
}

//地图区域划分，便于ai（这个ai是指怪物行动逻辑）逻辑控制
void area() {
	int n = 0, i = 0, a = 0, j = 0, k1 = 0, k2 = 0, k3 = 0;
	for (int h = 0; h <= 2; h++) {
		//printf("3,'%d'\n",a);
		for (j, k3 = j; j <= k3 + 1; j++) {
			//printf("2,'%d'\n",a);
			for (n, k2 = n; n <= k2 + 2; n++, i -= 2) {
				//printf("1,'%d'\n",a);
				for (i, k1 = i; i <= k1 + 1; i++, a++) {
					//printf("0,'%d'\n",a);
					map_area[n].con[i] = a;
				}
			}
			i = 2;//写这里是为了方便管理
			n -= 3;
		}
		i = 0;
		n += 3;
	}
}

//地图位置区域返回
int area_return(int* sit, int unit) {
	int n = 0, sw = 0, con = 0;
	if (unit == human || unit == human_keep) {
		for (int i = 0; i <= 35; i++) {
			if (sit[i] == human || sit[i] == human_keep) {
				con = i;
				break;
			}
		}
	}
	else if (unit == ghost_1 || unit == ghost_1_no_visual) {
		for (int i = 0; i <= 35; i++) {
			if (sit[i] == ghost_1 || sit[i] == ghost_1_no_visual) {
				con = i;
				break;
			}
		}
	}
	else if (unit == ghost_2 || unit == ghost_2_no_visual) {
		for (int i = 0; i <= 35; i++) {
			if (sit[i] == ghost_2 || sit[i] == ghost_2_no_visual) {
				con = i;
				break;
			}
		}
	}
	for (n; n <= 8; n++) {
		for (int i = 0; i <= 3; i++) {
			if (map_area[n].con[i] = con) {
				return n;
			}
		}
	}
	return -1;
}

//怪物位置控制(ai)(独立行动)
void ghost_move(int* sit, int ghost) {
	int play_sit = -1, gh_sit = -1;
	for (int i = 0; i <= 35; i++) {
		if (ghost == ghost_1 && (sit[i] == ghost_1 || sit[i] == ghost_1_no_visual)) {
			gh_sit = i;
		}
		if (ghost == ghost_2 && (sit[i] == ghost_2 || sit[i] == ghost_2_no_visual)) {
			gh_sit = i;
		}
		if (sit[i] == human || sit[i] == human_keep) {
			play_sit = i;
		}
	}
	if ((distance_x_or_y(play_sit, gh_sit, 'x') == 0 && distance_x_or_y(play_sit, gh_sit, 'y') == 1)) {
		if (coor_x_or_y(play_sit, 'y') - coor_x_or_y(gh_sit, 'y') >= 0) {
			sit[gh_sit] = empty;
			sit[gh_sit + 6] = ghost_1;
		}
		else {
			sit[gh_sit] = empty;
			sit[gh_sit - 6] = ghost_1;
		}
	}
	else if ((distance_x_or_y(play_sit, gh_sit, 'x') == 1 && distance_x_or_y(play_sit, gh_sit, 'y') == 0)) {
		if (coor_x_or_y(play_sit, 'x') - coor_x_or_y(gh_sit, 'x') >= 0) {
			sit[gh_sit] = empty;
			sit[gh_sit + 1] = ghost_1;
		}
		else {
			sit[gh_sit] = empty;
			sit[gh_sit - 1] = ghost_1;
		}
	}

}

//道具


//聊天
void chat() {

}

//成就1
void achievement_1(int lanuage, int bugger, int part) {
	if (part == 1) {
		switch (bugger) {
		case 1:printf("\n%s\n", lanuage_choose(lanuage, 19));
			break;
		case 2:printf("\n%s\n", lanuage_choose(lanuage, 20));
			break;
		case 3:printf("\n%s\n", lanuage_choose(lanuage, 21));
			break;
		case 4:printf("\n%s\n", lanuage_choose(lanuage, 22));
			break;
		case 5:
			printf("\t\t   Q\n\t\t   ||\n\t\t   ||\n\t\t   ||\n\t\t  @  @\n\t\t@|| | |  /@\n\t\t||| | | //\n\t\t|     | /\n\t\t\\");
			printf("\n\t\t%s\n", lanuage_choose(lanuage, 23));
			break;
		}
	}
}
