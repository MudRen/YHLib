#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Ĺ�ڲ�");
	set("long", @LONG
�������һ�߹ײģ���ž���Ĺ������д����˪�����Ĺ�
���ˡ���ֵ��ǹײ��ѱ��򿪣��Ա߷��Ź׸�(cover)��
LONG);

	set("exits", ([
		"north" : __DIR__"sec2",
	]));
	set("item_desc", ([
		"cover" : WHT "\n��Ĩȥ����Ļҳ���ֻ�������澹Ȼ����Щ����ֵֹ���\n"
                          "�֡�" NOR + HIR "��ʮ��" NOR + WHT "��" NOR + HIR "��"
                          "ʮ��" NOR + WHT "��" NOR + HIR "һʮ��" NOR + WHT "��"
                          NOR + HIR "��ʮ��" NOR + WHT "��" NOR + HIR "��ʮ��" NOR
                          + WHT "������ \n" NOR,
	]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

