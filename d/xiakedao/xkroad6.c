// Room: /d/xiakedao/xkroad6.c
// Modified by rcwiz
inherit ROOM;

void create()
{
        object ob;

	set("short", "���С��");
	set("long", @LONG
С�������С��ʮ�ּ�ª������ûʲô�ҵ������Ϲ��������þ�
�˵���ߡ����������˶������ˡ�
LONG );
	set("exits", ([
		"south"   : __DIR__"xkroad5",
	]));
               
	set("objects", ([
		  "/kungfu/class/xiakedao/zhangsan2" : 1,
	]));
           
        
	setup();
}
