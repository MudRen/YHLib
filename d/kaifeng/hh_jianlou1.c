#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", "�ؽ�¥һ��");
        set("long", @LONG
�����Ǻ컨��������޳������ľ���֮�����޳������ų�
׷�����������˽��˵���Ϊ���ؽ�¥����¥�����㣬һ¥��
��ܼ򵥣�Ω��һ��һ�Ρ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"hh_xiaojing1",
  		"up" : __DIR__"hh_jianlou2",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/wuchen" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "up")
        {
                if ((string)me->query("family/family_name") != "�컨��"
                & objectp(present("wuchen daozhang", environment(me))))
                        return notify_fail(CYN "�޳���������ȵ����η�����������"
                                           "������˽������֮�ء�\n" NOR);
        }
        return ::valid_leave(me, dir);
}
