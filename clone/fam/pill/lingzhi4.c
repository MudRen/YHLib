#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(HIG "ǧ����֥��" NOR, ({ "lingzhi wan", "lingzhi", "wan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "��ǧ����֥����������ҩ�������Ƶ���ҩ��\n" NOR);
                set("base_unit", "��");
                set("base_value", 30000);
                set("base_weight", 100);
                set("only_do_effect", 1);
                set("pill_skill", "force");
                set("skill_mapped", 1);
                set("pill_point", 40000);
                set("force_point", 100);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}
