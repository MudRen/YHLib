inherit ROOM;
string look_duilian();

#include <ansi.h>;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ�����ݵı�����ϲ࣬��Ϊ����������ţ�ʹ����
Ů���ٶ�ϲ����������ͥɢ������ͤ�з�����ȥ������һƬ��
�̵Ĳ�ƺ��ͤ����Ȼ���ʴ�֮�У���������������ƿƣ�����
�ܿ����ܣ�ͤ�ϵĶ��Һ�ʯ���ϵ����(lian)ʹ�˸���ϲ����
�
LONG );
	set("outdoors", "suzhou");
        set("item_desc",([
                "lian" : (: look_duilian :), //������±��޼� ��ˮԶɽ������
        ]));
	set("exits", ([
		"north" : __DIR__"beidajie1",
		"south" : __DIR__"zhongxin",
	]));
	set("objects", ([
		"/adm/npc/hongniang" : 1,
	]));
	setup();
}

string look_duilian()
{
        return
        HIC "\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "���塡" NOR + HIC "����            ����" NOR + HIW "  ��  " NOR + HIC "����\n"
        "             ������ �� ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIC "����            ����" NOR + HIW "  ˮ  " NOR + HIC "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIC "����            ����" NOR + HIW "  Զ  " NOR + HIC "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIC "����            ����" NOR + HIW "  ɽ  " NOR + HIC "����\n"
        "             ����      ����            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIC "����            ����" NOR + HIW "  ��  " NOR + HIC "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIC "����            ����" NOR + HIW "  ��  " NOR + HIC "����\n"
        "             ����    ������            ����      ����\n"
        "             ����" NOR + HIW "  ��  " NOR + HIC "����            ����" NOR + HIW "  ��  " NOR + HIC "����\n"
        "             ����    ������            ����      ����\n"
        "             ��������������            ��������������\n"
        "             ��������������            ��������������\n\n" NOR;
}
