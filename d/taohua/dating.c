inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", "����");
    set("long", 
"�������һ�ɽׯ����������������ʮ�ֿ��������и�����\n"
"�˸������ҵ��鷨�漣������Ϊ���۵�ȴ�����йҵ�һ��������\n\n"
HIC "           ������������������������������\n"
"           ��                          ��\n"
"           ��   " HIW "�� �� Ӱ �� �� �� ��" HIC  "   ��\n"
"           ��                          ��\n"
"           ��   " HIW "�� �� �� �� �� �� ��" HIC  "   ��\n"
"           ��                          ��\n"
"           ������������������������������\n\n" NOR
"�������پ�ͦ�Σ����ƺ�ΰ֮�������Ӧ�ǳ��Ի�ҩʦ���ֱʡ�\n"
);
	set("exits", ([
	    "north" : __DIR__"qianyuan",
	    "south" : __DIR__"houyuan",
	    "east"  : __DIR__"daojufang",
	    "west"  : __DIR__"wofang" ,
	]));
	set("objects", ([
	    "/kungfu/class/taohua/huang" : 1,
	]) );    
	set("valid_startroom", 1);
	set("no_beg", "1");
	setup();

	 "/clone/board/taohua_b"->foo();
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (! objectp(guarder = present("huang yaoshi", this_object())))
                return 1;

        if (dir == "south" || dir == "east")
                return guarder->permit_pass(me, dir);

        return 1;
}
