#include <ansi.h>
inherit ITEM;

#define MUOU    "/clone/lonely/book/18muou"

void create()
{
        set_name(NOR + WHT "ʮ����ż" NOR, ({ "18 niou", "18", "niou" }));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + WHT "
����һ��Сľ�У����е����޻�������������������ż��ÿ��
����������һʮ�˸�����ż�����÷ǳ����ɣ�ÿ�����������
���ˣ�Ƥ����Ϳ�˰��ѣ��������������ߣ����������ڵ㣬��
�������Ѩ���ķ�λ���ƺ����Ǻ��ڹ��ķ��йء�\n" NOR);
                set("value", 5000);
                set("no_sell", "��ҵĺ������ˣ����Ҳ������Ǯ��");
                set("material", "wood");
                set("skill", ([
                        "name"         : "force",
                        "exp_required" : 1000,
                        "jing_cost"    : 30,
                        "difficulty"   : 30,
                        "max_skill"    : 99,
                        "min_skill"    : 20
                ]));
        }
}

void init()
{
        add_action("do_nie", "nie");
}

int do_nie(string arg)
{
        object me, ob;
        object where;

        me = this_player();

        if (! arg || ! id(arg))
                return 0;

        ob = find_object(MUOU);
        if (! ob) ob = load_object(MUOU);

        if (! environment(ob))
        {
                ob->move(me, 1);
                message_sort(HIW "\nֻ��$N����һ�����е���ż������ˢˢˢ"
                             "������������������ķ��Ρ��Ͳʺ���׷׷׵�"
                             "�䡣$N�ĸп�ϧ��ȴ��������䴦��������һ��"
                             "�����ľ�档�����ٽ���۰���һЩ��������ϡ"
                             "�ֳ����Σ������ٽ��������ϵ���۾�����ȥ��"
                             "��¶��һ�������ľż����ľż�������Ų�ͩ��"
                             "���������ߣ�ȴ��Ѩ��λ�á�ľż�̹����ɣ���"
                             "Ŀ����������˫������������Ц״����̬����֮"
                             "������ò�ͱ��������˽�Ȼ��ͬ��\n\n" NOR, me);
        } else
        {
                message_sort(HIR "\n$N����һ�����е���ż������ˢˢ������"
                             "������������ķ����Ͳʺ���׷׷׵��䣬����"
                             "��ż������һ������ࡣ$N��������̾Ϣ��ԭ��"
                             "���п������Ǭ����û�뵽��Ȼ�װ���̣�˱���"
                             "��\n\n" NOR, me);
        }
        destruct(this_object());
        return 1;
}
