#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + WHT "������" NOR, ({ "buzhen xiang", "buzhen", "xiang" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ����Ϊ�¾ɵ�ī��ľ�䣬����"
                            "װ�и��ָ���\n�ĵ��ߣ����Ѱ��������������"
                            "��(" HIW "array" NOR + WHT ")��С�\n" NOR);
                set("unit", "��");
                set("value", 5000);
                set("no_sell", "�٣���������Ҳ����Ǯ��\n");
                set("count", 5);
                set("material", "wood");
        }
        setup();
}

void init()
{
        add_action("do_array", "array");
        add_action("do_array", "buzhen");
}

int do_array(string arg)
{
        object me, env, *ob;
        string desc;
        int skill;
        mapping exit;

        me = this_player();

        if (me->is_busy()
           || me->query_temp("pending/exercising")
           || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        env = environment(me);
        exit = env->query("exits");

        skill = (int)me->query_skill("qimen-wuxing", 1);

        if (skill < 1)
                return notify_fail("��Ѳ����䷭����ȥ��Ū�˰��죬ȴ"
                                   "��֪������֡�\n");

        if (query("count") < 1)
                return notify_fail("�������е�����Ѿ������ˡ�\n");

        if (skill < 120)
                return notify_fail("����������е��о������������޷�"
                                   "����\n");

        if (! env)
                return notify_fail("�����޷�����\n");

        if (wiz_level(me) < 3
           && (env->query("no_fight")
           || env->query("sleep_room")
           || env->query("skybook")
           || env->query("no_sleep_room")))
                return notify_fail("���ﲻ�������ŵĵط���\n");

        if (wiz_level(me) < 3 && ! env->query("outdoors"))
                return notify_fail("���ڿռ������С�����Բ���\n");

        if (env->query("th_buzhen"))
                return notify_fail("�����Ѿ����������󷨡�\n");

        if (me->query("max_jingli") < 800)
                return notify_fail("��ľ�����Ϊ���㣬���Բ���\n");

        if (me->query("jingli") < 500)
                return notify_fail("��Ŀǰ�ľ������㣬���Բ���\n");

        if (me->query("jing") < 300)
                return notify_fail("��Ŀǰ�ľ������㣬���Բ���\n");

        add("count", -1);
        me->receive_damage("jing", 200);
        me->add("jingli", -300);
        me->start_busy(5);

        message_sort(HIG "\n$N" HIG "΢΢һЦ����ذڳ�" NOR + WHT "������"
                     HIG "��������μ�ת��Ʈ�費����������Ѹ�ٲ���������"
                     "����ʱ�̳�����ɰʯ�ҷɣ�����ɷΪ���ˡ���һ�̣��ּ�"
                     "$N" HIG "�������θ��ֶ�����������Ӽž�������͸��һ��"
                     "��ɱ֮����\n\n" NOR, me);

        desc = env->query("long") + HIM "\nȴ���˴������ǳ����죬��ɫ������"
               "���ڿ��У�͸��ɭɭ������\n\n" NOR;

        env->set("org_desc", env->query("long"));
        env->set("org_exits", env->query("exits"));
        env->set("org_cost", env->query("cost"));
        env->set("long", desc);
        env->set("th_buzhen", 1);
        env->set("th_zhen_owner", me->query("id"));
        env->set("th_pozhen", skill);

        if (skill < 150)
        {
                env->set("exits", ([
                        "east"  : file_name(env),
                        "south" : file_name(env), 
                        "west"  : file_name(env),
                        "north" : file_name(env),
                ]));
        } else
        if (skill < 180)
        {
                env->set("exits", ([
                        "east"  : file_name(env),
                        "south" : file_name(env),
                        "west"  : file_name(env),
                        "north" : file_name(env),
                        "northwest" : file_name(env),
                        "northeast" : file_name(env),
                        "southeast" : file_name(env),
                        "southwest" : file_name(env),
                ]));
        } else
        {
                env->set("exits", ([
                        "east"  : file_name(env),
                        "south" : file_name(env),
                        "west"  : file_name(env),
                        "north" : file_name(env),
                        "enter" : file_name(env),
                        "out"   : file_name(env),
                        "up"    : file_name(env),
                        "down"  : file_name(env),
                        "northwest" : file_name(env),
                        "northeast" : file_name(env),
                        "southeast" : file_name(env),
                        "southwest" : file_name(env),
                ]));
        }
        call_out("remove_effect", skill / 2, env);
        return 1;
}

void remove_effect(object env)
{
        if (! env || ! env->query("th_buzhen"))
                return;

        env->set("long", env->query("org_desc"));
        env->set("exits", env->query("org_exits"));
        env->set("cost", env->query("org_cost"));
        env->delete("org_desc");
        env->delete("org_cost");
        env->delete("org_exits");
        env->delete("th_buzhen");
        env->delete("th_pozhen");
        env->delete("th_zhen_owner");

        tell_object(env, HIM "\nͻȻ��������Χɢȥ�����澰��"
                         "��Ȼһ�䡣\n\n" NOR);
}
