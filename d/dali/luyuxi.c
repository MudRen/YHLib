//Room: /d/dali/luyuxi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����Ϫ�ذ�");
	set("long",@LONG
һ���Ŀ�����·��������Ϫ�ϰ���ᶫ����һ������Ϫ����
����������һ������ɽ�����������де���ľ���������Ŷ�Ϫͨ���
������ţ���ȥ��Զ�����廪¥�ˡ�
LONG);
	set("outdoors", "dali");
	set("exits",([
	    "east"      : __DIR__"shuangheqiao",
	    "west"      : __DIR__"gudao",
	    "south"     : "/d/wudu/road1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

