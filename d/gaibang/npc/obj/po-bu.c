#include <ansi.h>
inherit ITEM;

string long();

void create()
{
        set_name(NOR + WHT "�Ʋ�" NOR, ({ "po bu", "po", "bu", "piece" }));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "����һ���Ʋ�����֪����ʲô�á�\n" NOR);
                set("material", "cloth");
                set("no_sell", "ʲô�����������ߡ�");
        }
}

string long()
{
        string msg;

        if (query("owner") && query("from"))
        {
                msg = WHT "����һ���" HIW + query("from") + NOR +
                      WHT "���������Ʋ���ɢ����һ���ͳ���ƾ�˿�ֱ"
                      "�������Ҫ��������ֻ���Ʋ���д�š����ս�"
                      "��" HIW + query("owner") + NOR + WHT "��ս"
                      "��ʤһ�ͬ����������������бб���֡�" NOR;
        } else
                msg = query("long");

        return sort_string(msg, 54);
}
