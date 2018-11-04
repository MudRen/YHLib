#include <ansi.h>
inherit ROOM;

string look_duilian();

void create()
{
        set("short", "������");
        set("long", 
"������Ϊ�������滳�õĵ������������ڴ˺�������š�\nɽ�ŵ����Ҷ�"
"��" HIR "���·�Ժ" NOR "�����ǵ���д�գ�����������" HIW "������\n"
"ɲ  �������" NOR "���ּ�������ɫ���š�ֻ��ɽ�ŵ�ǽ�����й���\n����(zi)"
"�������Զ���������ɱ硣�������ڵ�ʯ������һ��\n��(lian)���ּ�Բ���ת����"
"¶���档\n"
);
        set("exits", ([ 
                "southdown"  : __DIR__"shanlu9",
                "westup"     : __DIR__"sansheng",         
        ]));

        set("objects", ([
                __DIR__"npc/xiangke" : 2,
        ]));        

        set("item_desc", ([
            "zi":
HIW"\n
          �������з��  �������ߴ�����
          ʯ·���������  ɮ�����м�����
          ��յ��������  �����ɼ������
          �����Ϸ����ϴ�  ��̦��޺Զ���
\n\n"NOR,
            "lian" : (: look_duilian :),

        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


string look_duilian()
{
        return
        HIR "\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "������" NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ������ �� ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  Ϊ  " NOR + HIR "����            ����" NOR + HIW "  Ϊ  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ɽ  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  һ  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ɲ  " NOR + HIR "����            ����" NOR + HIW "  ��  " NOR + HIR "����\n"
        "             ����    ������            ����      ����\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n\n" NOR;
}





