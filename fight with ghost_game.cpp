//-----------------------------------------
//这里是全新的开始--Alex
//-----------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<windows.h>

//语言文本
#define PART0_E "choose you language,please"
#define PART0_C "请选择你的语言"
#define PART0_J "言語を選択してください"
#define PART0_R "Пожалуйста, выберите язык"
#define PART0_F "Veuillez choisir votre langue, s'il vous plaît"
#define PART0_Q ""
#define PART0_M_C ""
#define PART0_M_J ""

#define PART1_E "English[0]"
#define PART1_C "中文[1]"
#define PART1_R ""
#define PART1_F ""
#define PART1_Q ""
#define PART1_M_C ""
#define PART1_M_J ""


#define PART2_E "Please press right command for you need "
#define PART2_C "请按指示再次输入，不要瞎输"

#define PART3_E "This is game map,you are the'W'and the'G'is ghost"
#define PART3_C "下面是游戏地图，其中“W”为你的位置，“G”为鬼魂的位置"


#define PART4_E "Everyone can move or do some thing by one round"
#define PART4_C "各单位每回合均可十字方向移动一格或执行一次其他行为"


#define PART5_E "Who first touch others can kill him"
#define PART5_C "先踩到对方就能将其消灭，反之亦然"


#define PART6_E "you just can see ghost when ther near you and be careful their shoot"
#define PART6_C "另外你只有在鬼魂附近才能看到他们，哦，还有小心他们发出的寒气。"


#define PART7_E "You can move when enter a right command or long right command,if you want"
#define PART7_C "你可以按如下的指示移动，另外你还可以输入连续指令一次性移动，呵呵，如果你想的话"


#define PART8_E "upward[W] downward[S] left[A] right[D] stay[K]"
#define PART8_C "向上[W] 向下[S] 向左[A] 向右[D] 停留[K]"


#define PART9_E "there haven't road,boy"
#define PART9_C "这边走不了哦，骚年"


#define PART10_E "‘W’-- You,kill all ghost for victory"
#define PART10_C "“W”—— 你，消灭所有幽灵就能胜利"


#define PART11_E " 'G' -- The ghost ,have two(in normal difficulty),just can be find when they around you"
#define PART11_C "“G”—— 幽灵，有两只（除非你设置了别的难度），只有在你周围八格时才能被看到"


#define PART12_E "‘*’-- The cold from ghost,just move on straight line(just be find around you too),if you catch it will be frozen"
#define PART12_C "“*”—— 幽灵发出的寒气，只会朝一定方向直线移动，当你触碰到时会被冻住一回合，同样只有在周围八格才能被发现"


#define PART13_E "The distance(in you 'n'th outward circle) by one of ghost:"
#define PART13_C "其中一个随机幽灵与你的距离（以你为中心向外的第n圈）为："


#define PART14_E "You are win"
#define PART14_C "你赢了"


#define PART15_E "Oh,you die"
#define PART15_C "吼，死了啦"


#define PART16_E "You just complete rounds is:"
#define PART16_C "这是你刚刚进行的回合数："


#define PART17_E "How do you feel? Do you want play again?"
#define PART17_C "感觉怎样？还要再玩一次吗"


#define PART18_E "again[0]   no,quit[1]   no,but I want to chat with you[2]"
#define PART18_C "再来一次吧[0]  不了，退出[1]  不了，但是我想和你聊聊[2]"


#define PART19_E "It`s wrong instruction"
#define PART19_C "你输错了，看好再输吧"


#define PART20_E "Can you enter right instruction?"
#define PART20_C "额，都最后了好好按指示输行不"


#define PART21_E "You did in intentionally,right"
#define PART21_C "你故意的吧"


#define PART22_E "......"
#define PART22_C "。。。。。。"


#define PART23_E "FUCK YOU"
#define PART23_C "去你的"


#define PART24_E ""
#define PART24_C ""


#define PART25_E ""
#define PART25_C ""


#define PART26_E ""
#define PART26_C ""


#define PART27_E "What are you fuck play"
#define PART27_C "去你的，别玩了"


#define PART28_E ""
#define PART28_C ""


#define PART29_E ""
#define PART29_C ""


#define PART30_E ""
#define PART30_C ""


#define PART31_E ""
#define PART31_C ""



/*void lanuage_cont() {
	const char* PART1_E = "choose you language please"
}

struct {
	char PART_1;
	char PART_2;
	char PART_3;
	char PART_4;
   }lanuage_choose[2]{1,2};//中文,英文

   static void lanuage() {
	   lanuage_choose.PART_1 =  PART1_C ;
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
}PART_seat[6];

//地图区域划分
struct {
	int con[4];
}map_area[9];

//------------new------------
// 这里很奇怪，实际上是完全非法的写法但还是能正常运行,但是他能简化很多流程
//鬼魂组
struct {
	bool life = false;
	int ID = -1;
	int* site = NULL;
	int kind = -1;
}Ghost[];
//玩家组
struct {
	bool lift = false;
	int ID = -1;
	char* name;
	int* site = NULL;
	int equipment = 0;
}Player[];

//正常应该这样
//鬼魂组
typedef struct Ghost{
	bool life;
	int ID;
	int* site;
	int kind;
};
//玩家组
typedef struct Player{
	bool lift;
	int ID;
	char* name;
	int* site;
	int equipment;
};

//锚点（这里使用了全新的概念，源于一次灵感的爆发）
typedef struct Anchor {
	int* anchor;
	int xSide;
	int ySide;
};

//---------------------------

//文本语言存储（对应的语言，对应的文本）
const char* lanuage_choose(int a, int b) {
	const char* lanuage_con[lanuage_number][50]{
		{PART0_E,PART1_E,PART2_E,PART3_E ,PART4_E,PART5_E,PART6_E,PART7_E,PART8_E,PART9_E,PART10_E,PART11_E,PART12_E,PART13_E,PART14_E,PART15_E,PART16_E,PART17_E,PART18_E,PART19_E,PART20_E,PART21_E,PART22_E,PART23_E,PART24_E,PART25_E,PART26_E,PART27_E,PART28_E,PART29_E,PART30_E},
		{PART0_C,PART1_C,PART2_C,PART3_C ,PART4_C,PART5_C,PART6_C,PART7_C,PART8_C,PART9_C,PART10_C,PART11_C,PART12_C,PART13_C,PART14_C,PART15_C,PART16_C,PART17_C,PART18_C,PART19_C,PART20_C,PART21_C,PART22_C,PART23_C,PART24_C,PART25_C,PART26_C,PART27_C,PART28_C,PART29_C,PART30_C},
	};
	return lanuage_con[a][b];
}

//文本颜色
void color(int color);
//随机数（随机数的范围）
int random(int limit);
//随机数库检验（读取随机数数组，读取位置，位置链接，检测模式（0：初始化；1：避开现有位置））（使库中的各数不重复）
int random_test(int* ran, int* seat, int i, int check_mode);
//随机数库（读取随机数数组，读取位置，需求模式(0:初始；1：避开现有位置)）
void random_con(int* ran, int* sit, int check_mode);
//字符串获取
char* GetString();
//人物填充（数组，调用随机数数组确定初位置，单位种类）
void entity(int* seat, int entity_seat, int type);
//坐标系设置
void seat_patch();
//单位x或y的坐标值（单位位置，提供x或y）
int coor_x_or_y(int unit_seat, char x_or_y);
//两单位间x或y的距离（单位1的位置，单位2的位置，提供x或y）
int distance_x_or_y(int unit_1, int unit_2, char x_or_y);
//结果判断
int end(bool play, bool ghost1, bool ghost2);
//所有单位的状态处理
void unit_status(int* seat, bool* play_p, bool* ghost1_p, bool* ghost2_p);
//任意一幽灵与玩家的距离
int ran_ghost_dis(int* seat, bool play, bool ghost1, bool ghost2);
//地图打印
void map_print(int* seat);
//人物位置控制
void player_seat(int* seat, int lanuage);
//地图区域划分，便于ai（这个ai是指怪物行动逻辑）逻辑控制
void area();
//地图位置区域返回
int area_return(int* seat, int unit);
//怪物位置控制(ai)(独立行动)
void ghost_move(int* seat, int ghost);
//道具

//聊天
void chat();
//成就1
void achievement_1(int lanuage, int bugger, int PART);


//主程序
int main() {
	int lanuage = 0, bugger = 0, repeat = 0, round = 0, input;
	bool play = true, ghost1 = true, ghost2 = true;//单位状态
	bool* play_p = &play, * ghost1_p = &ghost1, * ghost2_p = &ghost2;//单位状态的指针
	int seat[36]{ 0 }, ran[num_all_thing + 1]{ 0 };//seat用于存储单位的地图位置，ran则是不重复的随机数段
	const int red = 4, green = 2, blue = 1;//字体颜色
	srand(time(NULL));//随机数种子设置

	//----------new----------------------
	
	//这里是验证出非法写法确实可用。。。
	//for (int i = 0; i < 99; i++) {
	//	Ghost[i].ID = i+1;
	//	Ghost[i].kind = random(2);
	//	Ghost[i].site = random(50);
	//}
	//for (int i = 0; i < 99; i++) {
	//	printf("%d %d %d \n", Ghost[i].ID,Ghost[i].kind,Ghost[i].site);
	//}

	Anchor anchor[1];

	int x = 6, y = 6;

	int* newMap = (int*)calloc(x * y , sizeof(int));//这里虽然是一维数组，但大家要把它想象成二维的
	anchor[0].anchor = &newMap[0];
	anchor[0].xSide = x;
	anchor[0].ySide = y;
	
	// -----------------------------------
	
	//内存分配（改为静态指针了，所以不需要了）
	//for (int i = 0; i <= 35;i++) {
		//seat[i] = (int*)malloc(sizeof(int));
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
	seat_patch();
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
			entity(seat, i, empty);
		}
		for (int i = 0; i <= num_all_thing; i++)
		{
			ran[i] = 40;
		}
		//建立随机数数库
		random_con(ran, seat, 0);
		//地图单位初设置
		entity(seat, ran[0], human);
		entity(seat, ran[1], ghost_1);
		entity(seat, ran[2], ghost_2);
		//for (int i=0; i <= num_all_thing;i++) {
		//	free(ran[i]);  原定的内存释放，同样不需要了
		//}
		while (1) {//主要的游戏运行部分
			unit_status(seat, play_p, ghost1_p, ghost2_p);
			map_print(seat);//地图打印
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
			printf("%s%d\n\n", lanuage_choose(lanuage, 13), ran_ghost_dis(seat, play, ghost1, ghost2));
			//输入指示
			printf("%s\n", lanuage_choose(lanuage, 7));
			//输入指令
			player_seat(seat, lanuage);
			//怪物行动
			if (ghost1) {
				ghost_move(seat, ghost_1);
			}
			if (ghost2) {
				ghost_move(seat, ghost_2);
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
int random_test(int* ran, int* seat, int i, int check_mode) {
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
			if (seat[ran[i]] != 0) {
				return 1;
			}
		}
	}return 0;
}

//随机数库（读取随机数数组，读取位置，需求模式(0:初始；1：避开现有位置)）
void random_con(int* ran, int* seat, int check_mode) {
	for (int i = 0; i <= num_all_thing; i++) {
		ran[i] = random(36);
		if (random_test(ran, seat, i, check_mode) == 1) {
			i--;
		}
	}
}

//人物填充（数组，调用随机数数组确定初位置，单位种类）
void entity(int* seat, int entity_seat, int type) {
	seat[entity_seat] = type;
}

//坐标系设置
void seat_patch() {
	for (int i = 0; i <= 5; i++) {
		for (int n = 0, m = 0; n <= 5; n++, m += 6)
		{
			PART_seat[i].con[n] = m + i;
		}
	}
}

//单位x或y的坐标值（单位位置，提供x或y）
int coor_x_or_y(int unit_seat, char x_or_y) {
	int save_1_x = -1, save_1_y = -1;
	for (int i = 0; i <= 5; i++) {
		for (int n = 0; n <= 5; n++)
		{
			if (PART_seat[i].con[n] == unit_seat) {
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

//字符串获取
char* GetString() {
	int stringLong = 1;
	char* stringCon = (char*)malloc(stringLong * sizeof(char));
	char charCon;
	while ( (charCon = getchar()) != '\n') {
		stringCon += charCon;
		if (stringLong >= 100) {
			return (char*)"1";
			stringCon = (char*)realloc(stringCon, stringLong++ * sizeof(char));
		}
	}
	return;
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
void unit_status(int* seat, bool* play_p, bool* ghost1_p, bool* ghost2_p) {
	int g_1_seat = 40, g_2_seat = 40, p_seat = 40;
	for (int i = 0; i <= 35; i++) {
		if (seat[i] == ghost_1 || seat[i] == ghost_1_no_visual) {
			g_1_seat = i;
		}
		if (seat[i] == ghost_2 || seat[i] == ghost_2_no_visual) {
			g_2_seat = i;
		}
		if (seat[i] == human || seat[i] == human_keep) {
			p_seat = i;
		}
	}
	if (p_seat == 40) {
		*play_p = false;
	}
	if (g_1_seat == 40) {
		*ghost1_p = false;
	}
	if (g_2_seat == 40) {
		*ghost2_p = false;
	}
	if (p_seat != 40) {
		if (g_1_seat != 40 && g_2_seat != 40) {
			if (distance_x_or_y(p_seat, g_1_seat, 'x') <= 1 && distance_x_or_y(p_seat, g_1_seat, 'y') <= 1) {
				seat[g_1_seat] = ghost_1_no_visual;
			}
			else {
				seat[g_1_seat] = ghost_1;
			}
			if (distance_x_or_y(p_seat, g_2_seat, 'x') <= 1 && distance_x_or_y(p_seat, g_2_seat, 'y') <= 1) {
				seat[g_2_seat] = ghost_2_no_visual;
			}
			else {
				seat[g_2_seat] = ghost_2;
			}
		}
		else if (g_1_seat != 40 && g_2_seat == 40) {
			if (distance_x_or_y(p_seat, g_1_seat, 'x') <= 1 && distance_x_or_y(p_seat, g_1_seat, 'y') <= 1) {
				seat[g_1_seat] = ghost_1_no_visual;
			}
			else {
				seat[g_1_seat] = ghost_1;
			}
		}
		else if (g_1_seat == 40 && g_2_seat != 40) {
			if (distance_x_or_y(p_seat, g_2_seat, 'x') <= 1 && distance_x_or_y(p_seat, g_2_seat, 'y') <= 1) {
				seat[g_2_seat] = ghost_2_no_visual;
			}
			else {
				seat[g_2_seat] = ghost_2;
			}
		}
	}
	else {
		seat[g_1_seat] = ghost_1;
		seat[g_2_seat] = ghost_2;
	}
}

//任意一幽灵与玩家的距离
int ran_ghost_dis(int* seat, bool play, bool ghost1, bool ghost2) {
	int g_1_seat, g_2_seat, p_seat;
	if (play && ghost1 || ghost2) {
		for (int i = 0; i <= 35; i++) {
			if (ghost1 && seat[i] == ghost_1 || seat[i] == ghost_1_no_visual) {
				g_1_seat = i;
			}
			if (ghost2 && seat[i] == ghost_2 || seat[i] == ghost_2_no_visual) {
				g_2_seat = i;
			}
			if (seat[i] == human || seat[i] == human_keep) {
				p_seat = i;
			}
		}
		if (ghost1 && ghost2) {
			if (random(2) == 1) {
				return max(distance_x_or_y(g_1_seat, p_seat, 'x'), distance_x_or_y(g_1_seat, p_seat, 'y'));
			}
			else {
				return max(distance_x_or_y(g_2_seat, p_seat, 'x'), distance_x_or_y(g_2_seat, p_seat, 'y'));
			}
		}
		else {
			if (ghost1) {
				return max(distance_x_or_y(g_1_seat, p_seat, 'x'), distance_x_or_y(g_1_seat, p_seat, 'y'));
			}
			else {
				return max(distance_x_or_y(g_2_seat, p_seat, 'x'), distance_x_or_y(g_2_seat, p_seat, 'y'));
			}
		}
	}
}


//地图打印
void map_print(int* seat) {
	int n = 0, m = 5;
	for (int i = 1; i <= 6; i++, m += 6) {
		printf("\n+---+---+---+---+---+---+\n|");
		for (n; n <= m; n++) {
			switch (seat[n])
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
void player_seat(int* seat, int lanuage) {
	int p_seat = 40, i = 0;
	char input;
	for (i; i <= 35; i++)
	{
		if (seat[i] == human) {
			p_seat = i;
			break;
		}
	}
	if (p_seat == 40) {

	}
	else {
		printf("%s\n", lanuage_choose(lanuage, 8));
		while (1) {
			printf(">>>");
			scanf_s(" %c", &input);
			if (input == 'W' || input == 'w') {
				if (p_seat >= 0 && p_seat <= 5) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_seat -= 6;
					break;
				}
			}
			else if (input == 'S' || input == 's') {
				if (p_seat >= 30 && p_seat <= 35) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_seat += 6;
					break;
				}
			}
			else if (input == 'A' || input == 'a') {
				if (p_seat == 0 || p_seat == 6 || p_seat == 12 || p_seat == 18 || p_seat == 24 || p_seat == 30) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_seat--;
					break;
				}
			}
			else if (input == 'D' || input == 'd') {
				if (p_seat == 5 || p_seat == 11 || p_seat == 17 || p_seat == 23 || p_seat == 29 || p_seat == 35) {
					printf("%s\n%s\n", lanuage_choose(lanuage, 9), lanuage_choose(lanuage, 8));
				}
				else {
					p_seat++;
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
		entity(seat, i, empty);
		entity(seat, p_seat, human);
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
int area_return(int* seat, int unit) {
	int n = 0, sw = 0, con = 0;
	if (unit == human || unit == human_keep) {
		for (int i = 0; i <= 35; i++) {
			if (seat[i] == human || seat[i] == human_keep) {
				con = i;
				break;
			}
		}
	}
	else if (unit == ghost_1 || unit == ghost_1_no_visual) {
		for (int i = 0; i <= 35; i++) {
			if (seat[i] == ghost_1 || seat[i] == ghost_1_no_visual) {
				con = i;
				break;
			}
		}
	}
	else if (unit == ghost_2 || unit == ghost_2_no_visual) {
		for (int i = 0; i <= 35; i++) {
			if (seat[i] == ghost_2 || seat[i] == ghost_2_no_visual) {
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
void ghost_move(int* seat, int ghost) {
	int play_seat = -1, gh_seat = -1;
	for (int i = 0; i <= 35; i++) {
		if (ghost == ghost_1 && (seat[i] == ghost_1 || seat[i] == ghost_1_no_visual)) {
			gh_seat = i;
		}
		if (ghost == ghost_2 && (seat[i] == ghost_2 || seat[i] == ghost_2_no_visual)) {
			gh_seat = i;
		}
		if (seat[i] == human || seat[i] == human_keep) {
			play_seat = i;
		}
	}
	if ((distance_x_or_y(play_seat, gh_seat, 'x') == 0 && distance_x_or_y(play_seat, gh_seat, 'y') == 1)) {
		if (coor_x_or_y(play_seat, 'y') - coor_x_or_y(gh_seat, 'y') >= 0) {
			seat[gh_seat] = empty;
			seat[gh_seat + 6] = ghost_1;
		}
		else {
			seat[gh_seat] = empty;
			seat[gh_seat - 6] = ghost_1;
		}
	}
	else if ((distance_x_or_y(play_seat, gh_seat, 'x') == 1 && distance_x_or_y(play_seat, gh_seat, 'y') == 0)) {
		if (coor_x_or_y(play_seat, 'x') - coor_x_or_y(gh_seat, 'x') >= 0) {
			seat[gh_seat] = empty;
			seat[gh_seat + 1] = ghost_1;
		}
		else {
			seat[gh_seat] = empty;
			seat[gh_seat - 1] = ghost_1;
		}
	}

}

//道具


//聊天
void chat() {

}

//成就1
void achievement_1(int lanuage, int bugger, int PART) {
	if (PART == 1) {
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
