#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(NOR + CYN "������֥" NOR, ({ "bainian lingzhi", "bainian",
                                              "lingzhi", "ling", "zhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "���ڸ�ɽ�ϵ����ҩ�ģ����ú�������ڹ��ȼ���\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 300);
                set("only_do_effect", 1);
                set("pill_skill", "force");
                set("skill_mapped", 1);
                set("pill_point", 20000);
                set("force_point", 3);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}
