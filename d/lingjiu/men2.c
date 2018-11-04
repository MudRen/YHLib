inherit ROOM;
#include <ansi.h>

string look_duilian();
string look_bian();

void create()
{
        set("short", "�鷿����");
        set("long",@LONG
�����鷿�ſڣ�ֻ�����������Ÿ����� (duilian)��̧ͷ
�����������һ�����(bian)��д�ż������֡�
LONG);
        set("outdoors", "lingjiu");
        set("exits", ([
                "east" : __DIR__"shufang",
                "west" : __DIR__"changl12",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/zhujian" : 1,
        ]));
        set("item_desc", ([
                "duilian" :       (: look_duilian :),
                "bian"    :       (: look_bian :),
        ]));
        setup();
}

string look_duilian()
{
        return
        HIR "\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "���С�" NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ������ �� ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ˮ  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ʱ  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n\n" NOR;
}

string look_bian()
{
    return
    "\n"
              HIY "               ####################################\n"
                  "               ####                            ####\n"
                  "               ####    ��    ��    ��    ң    ####\n"  
                  "               ####                            ####\n"
                  "               ####################################\n\n\n\n\n\n\n" NOR;
    "\n";
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (dir != "east")
                return 1;

        if (objectp(guarder = present("zhu jian", environment(me))))
                return guarder->permit_pass(me, dir);

        return 1;
}
