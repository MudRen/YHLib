inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��վ��һ����������������ǰ����ǰ����ֻ�����ʯʨ
�ӣ����ϸ���һ����ң����顸�����������ĸ����֡��ſ�
վ���������������Ž��£���ִ�ֵ�������������
LONG);
	set("objects", ([
	   	CLASS_D("duan") + "/chu" : 1,
	   	__DIR__"npc/weishi1" : 2,
	]));
	set("valid_startroom", 1);
        set("no_sleep_room", 1);
	set("outdoors", "dali");
	set("exits", ([
	    	"enter"  : __DIR__"wfdating",
	    	"south"  : __DIR__"wangfulu",
	]));
	setup();
	"/clone/board/dali_b"->foo();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (dir == "enter" && ob = present("chu wanli", this_object()))
                return ob->permit_pass(me, dir);

        return ::valid_leave(me, dir);
}
