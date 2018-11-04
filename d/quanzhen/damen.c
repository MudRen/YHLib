#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_duilian();

void create()
{
        set("short", "ȫ��̴���");
        set("long",
"�����ߵ�������ɽ��ɽ��������ȫ��̵��ܲ�����������
����ɽ�������ߵʹ������¡����Ϲ���һ��������д�ţ�

           " WHT "��������������������������������
           ��                            ��
           ��" NOR + HIW "     ��      ��      ��" NOR + WHT "     ��
           ��                            ��
           ��������������������������������" NOR "

�������֡���ǰ��ʯ���Ϲ���һ������ (duilian)����Χ��ľ
ɭɭ��������֣���ɫ���ġ���ǰ����ǽ���߷������ݣ�����
��һ�����������������ߵ����ɼľ��ͭ���š�\n");

        set("exits", ([
                "east" : __DIR__"datang1",
                "westdown" : __DIR__"jiaobei",
        ]));

        set("item_desc", ([
                "duilian" : (: look_duilian :),
        ]));

        set("objects",([
                __DIR__"npc/zhike" : 1,
        ]));
        create_door("east", YEL "��ͭ����" NOR, "west", DOOR_CLOSED);
        set("outdoors", "quanzhen");
        setup();
}

string look_duilian()
{
        return
        HIR "\n"
        "       ��������������            ��������������\n"
        "       ��������������            ��������������\n"
        "       ����      ����            ����      ����\n"
        "       ����" NOR + HIW "��һ��" NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ������ �� ����            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����      ����            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����      ����            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����      ����            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����    ������            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����    ������            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����      ����            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����    ������            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "       ����    ������            ����      ����\n"
        "       ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  Ȼ  " NOR + HIR "����\n"
        "       ����    ������            ����      ����\n"
        "       ��������������            ��������������\n"
        "       ��������������            ��������������\n\n" NOR;
}
