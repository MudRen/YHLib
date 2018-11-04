inherit ROOM;
string look_duilian();

#include <ansi.h>;

void create()
{
        set("short", "������");
        set("long", 
"������������ǵĸ���֮��--�����������������������
�δ��£����Ŷ����ڴ��ټ����ˣ�����ʩ�������ǽ�ϣ�����
һ�����˵�Ф���ǵ��������Ǵ�����ʦ���������������Ͽ�
��һ������(duilian)���Աߵı������Ϸ����˺��������ĳ�����
�ö����һ���ң������ĸ����֡�" HIW "

                  ÷    ѩ    ��    ��
\n" NOR );
        set("item_desc",([
                "duilian"         :       (: look_duilian :),
        ]));
        set("exits", ([
                "east"  : __DIR__"fudian2",
                "west"  : __DIR__"fudian1",
                "north"  : __DIR__"qianyuan",
                "south"  : __DIR__"meiroad1",
        ]));
        set("objects", ([
                CLASS_D("lingxiao") + "/luwantong" : 1,
                __DIR__"npc/dizi" : 4,
        ]));
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
        "/clone/board/lingxiao_b"->foo();
} 

string look_duilian()
{
        return
        HIR "\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "������" NOR + HIR "����            ����" NOR + HIW "  ÷  " NOR + HIR "����\n"
        "             ������ �� ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ĥ  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n\n" NOR;
}

int valid_leave(object me, string dir)
{
        object lu;

        if (dir != "east" &&
            dir != "west" &&
            dir != "north" ||
            ! objectp(lu = present("lu wantong", this_object())))
                return ::valid_leave(me, dir);

        return lu->permit_pass(me, dir);
}
