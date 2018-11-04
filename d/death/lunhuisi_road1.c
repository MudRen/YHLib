#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_duilian();

void create()
{
        set("short", HIB "���ֻص���" NOR);
        set("long", HIB @LONG

                    ��         ��         ��

    �ֻص��Ϻ���ɭɭ�ģ���ʯ����ĵ������ǻҳ�������һƬ�ž���ż
����������ԩ��Ұ�����������ʹ�����Եø���Ŀֲ����졣�����ǰ��
һ����ΰ�Ĵ����õĸ�����д�š��ֻ�˾���������֣�������һ����
ȱ��ȫ�Ķ���(duilian)���ֻ�˾�޴��ʵ��ͭ��(door)�����ر��š�

LONG NOR );

        set("exits", ([
                "enter" : __DIR__"lunhuisi",
        ]));

        set("item_desc", ([
                "door" : YEL "һ�Ⱥ���ͭ�ţ����沼���������ͻҳ���\n" NOR,
                "duilian" :       (: look_duilian :),
        ]));

        create_door("enter", YEL "ͭ��" NOR, "out", DOOR_CLOSED);
        setup();
       replace_program(ROOM);
}

string look_duilian()
{
        return
        RED "\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "���졡" NOR + RED "����            ����" NOR + HIW "  Ѫ  " NOR + RED "����\n"
        "             ������ �� ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ʱ  " NOR + RED "����            ����" NOR + HIW "  ��  " NOR + RED "����\n"
        "             ����    ������            ����      ����\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n" NOR;
}
