#include <ansi.h>
#include <armor.h>

inherit F_OBSAVE;
inherit ARMOR;

void create()
{
        set_name(HIR "��������" NOR, ({ "longxiang jiasha", "longxiang", "jiasha" }));
        set_weight(8000);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIR "����һ���¾ɵ����ģ�ͨ��Ѫ�죬ӡ��������������"
                            "�ִ�����\n�ޱȣ�������ɽ��˿�켰ѩ��˿��֯���ɡ�"
                            "���д���˵����\n��������������Ǽ������������֮"
                            "�ϡ�\n" NOR);
                set("value", 100000);
                set("no_sell", "�ҡ��ҵ��졭�ɹŹ�ʦ���·���Ҳ����������");
                set("material", "cloth");
                set("wear_msg", HIY "$N" HIY "չ��$n" HIY "����ʱ����ת�����"
                                "����ȫ��\n" NOR);
                set("armor_prop/armor", 200);
                set("skill", ([
                        "name" : "longxiang-gong",
                        "exp_required" : 1000000,
                        "jing_cost"    : 200,
                        "difficulty"   : 80,
                        "max_skill"    : 299,
                        "min_skill"    : 210,
                        "need"         : ([ "sanscrit" : 200 ]),
                ]));
                // ��ʼ�ֵ������趨Ϊʮ����װ������Եֵ�ʮ�����κι�����
                // �Ժ�ÿע��һ���������Զ�ֵ�һ�ι���������Ϊʮ���Ρ�
                set("force", 13);
                set("stable", 100);
        }
        setup();
}

void init()
{
        add_action("do_force", "force");
}

int do_force(string arg)
{
        object me = this_player();

        if (! arg || ! id(arg))
                return notify_fail("�����������ע��������\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�����ʱ��æ�����\n"); 

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n"); 

        if (query("equipped"))
                return notify_fail("������Ƚ�" + name() + "���¡�\n");

        if ((int)me->query_skill("longxiang-gong", 1) < 280)
                return notify_fail("�������������Ϊ���������Խ�����ע�����ġ�\n");

        if (me->query_skill_mapped("force") != "longxiang-gong")
                return notify_fail("��û�м�����������������Խ�����ע�����ġ�\n");

        if (me->query("max_neili") < 6000)
                return notify_fail("��Ŀǰ��������Ϊ���������Խ�����ע�����ġ�\n");

        if (me->query("neili") < me->query("max_neili"))
                return notify_fail("��Ŀǰ�������в����������Խ�����ע�����ġ�\n");

        if (query("force") >= 13)
                return notify_fail("����������Ȼ���ͣ��޷������ɸ����������\n");

        me->set("neili", 0);
        me->add("max_neili", -5);
        me->start_busy(5);
        add("force", 1);
        message_sort(HIY "\n$N" HIY "΢һ����ĬĬ�˾����������������˫�ƽ�"
                     "��ѹס" + name() + HIY "���ࡣ����Ƭ��" + name() + HIY
                     "��Ȼ���������ƺ��ѽ����������������С�$N" HIY "��״��"
                     "æ�ջ�˫�ƣ���ɫ���˱䣬��������˥�ߡ�\n\n" NOR, me);
        return 1;
}

mixed valid_damage(object ob, object me, int damage)
{
        if (query("force") > 0)
	{
                add("force", -1);
                return ([ "damage" : -damage,
                          "msg" : HIY "��ʱֻ��" + name() + HIY "��һ���⻪��"
                                  "������Ȼ��$N" HIY "��һ�л������Ρ�\n" NOR ]);
	}
}

// ���б������ݵĽӿں���
mixed save_dbase_data()
{
        mapping data;

        data = ([ "force" : query("force") ]);

        return data;
}

// ���ܴ������ݵĽӿں���
int receive_dbase_data(mixed data)
{
        if (! mapp(data))
                return 0;

        if (! undefinedp(data["force"]))
        {
                set("force", data["force"]);
        }
        return 1;
}

