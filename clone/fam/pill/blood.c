#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(HIG "����" HIR "Ѫ" HIG "��" NOR, ({ "bipo xuejing", "bipo", "xuejing" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "��Ө��͸��Ѫ�����˴�ѩɽ������������Ѫ��"
                                "�����ɡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 300);
                set("only_do_effect", 1);
                set("pill_skill", "force");
                set("pill_point", 5000);
                set("force_point", 20);
                set("pill_msg1", HIG "��ֻ��һ�����ߴ��ʺ�ֱͨ�����У�ȫ"
                                 "������̩�ޱȡ�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ�����ߴ��ʺ�ֱͨ�����У���"
                                 "Ϣ�õ���ȫ���䡣\n" NOR);
        }
        setup();
}
