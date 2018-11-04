#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "�̼ұ�����");
	set("long", @LONG
�������̼ұ��Ĵ����������ں��ǿ����������Ͽ���һ��
�޴�������ԡ��������Űڷ���һ�Ű�������һ��ѹ�����ã���
�ĸߴ���࣬���Ŷ��룬������Ϊ���࣬���ǡ����Ե����̽�����
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_houting",
		"south"  : __DIR__"shang_xiaojin2",
		"east"  : __DIR__"shang_tinge",
		"west"  : __DIR__"shang_tingw",
	]));
        set("objects", ([
                CLASS_D("shang") + "/ming" : 1,
        ]));
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
        "/clone/board/shang_b"->foo();
}


int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "north" || 
           dir == "east" || 
           dir == "west")
        {
                if ((string)me->query("family/family_name") != "�̼ұ�" &&
                   (string)me->query("born_family") != "ɽ���̼�" &&
                   objectp(present("shang jianming", environment(me))))
                        return notify_fail(CYN "�̽�������ȵ���ʲô��������Ȼ"
                                           "��������ǰ������\n" NOR);
        }
        return ::valid_leave(me, dir);
}
