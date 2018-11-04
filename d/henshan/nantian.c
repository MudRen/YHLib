#include <ansi.h>
inherit ROOM;

string look_duilian();

void create()
{
        set("short", "������");
        set("long", 
"���������ţ�����������ɽ��һ��ף�ڷ塣�������ǻ���\n�����ɵ�ʯ������"
"�������С�" HIC " ������ " NOR "�����ֺ����Ҷ���\n������ϣ���"
"����С�" HIW "����" NOR "���͡�" HIW "ʩ��" NOR "�����֡����(lian)��"
"\nª���Լ������Ѿá�\n"
);
        set("item_desc",([
                "lian" : (: look_duilian :),
        ]));
        set("exits", ([
                "eastup"    : __DIR__"liuyunping",
                "northeast" : __DIR__"shiziyan",
                "northwest" : __DIR__"shanlu14",
                "southeast" : __DIR__"denggaotai",
                "southwest" : __DIR__"shanlu13",
        ]));
 
        set("objects", ([
                __DIR__"npc/dizi1" :  4,
        ]));

        set("outdoors", "henshan");
        setup();
        replace_program(ROOM);
}

string look_duilian()
{
        return
        HIC "\n"
        "\t��������������        ��������������\n"
        "\t��������������        ��������������\n"
        "\t����      ����        ����      ����\n"
        "\t����" NOR + WHT "���š�" HIC "����        ����" NOR + WHT "  ·  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" NOR + WHT "���ɡ�" HIC "����        ����" NOR + WHT "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" NOR + WHT "��ͨ��" HIC "����        ����" NOR + WHT "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" NOR + WHT "���졡" HIC "����        ����" NOR + WHT "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "������" HIC "����        ����" HIW "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "���ۡ�" HIC "����        ����" HIW "  �  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "���̡�" HIC "����        ����" HIW "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "���䡡" HIC "����        ����" HIW "  ΢  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "���ǡ�" HIC "����        ����" HIW "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "������" HIC "����        ����" HIW "  ��  " HIC "����\n"
        "\t������ �� ����        ����      ����\n"
        "\t����" HIW "������" HIC "����        ����" HIW "  ��  " HIC "����\n"
        "\t����    ������        ����      ����\n"
        "\t��������������        ��������������\n"
        "\t��������������        ��������������\n\n" NOR;
}
