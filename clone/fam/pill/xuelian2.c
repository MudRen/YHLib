#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(HIC "ǧ��ѩ��" NOR, ({ "qiannian xuelian", "qiannian",
                                        "xuelian", "lian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���\n" NOR);
                set("base_unit", "��");
                set("base_value", 15000);
                set("base_weight", 300);
                set("only_do_effect", 1);
                set("pill_skill", "dodge");
                set("pill_point", 38000);
                set("force_point", 5);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}
