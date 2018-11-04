// xuxiake.c ��ϼ��

#include <ansi.h>
inherit NPC;

mixed ask_map();

void create()
{
        set_name("��ϼ��", ({ "xu xiake", "xu", "xiake" }));
        set("long", @LONG
�������߱����£���ʶ��������������ۣ���
ɽ������Ī������ָ�ơ�
LONG);
        set("gender", "����");
        set("age", 45);
        set("attitude", "friendly");
        set("inquiry", ([
                "��ͼ" : (: ask_map :),
                "map"  : (: ask_map :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

mixed ask_map()
{
        object me, ob;
        mapping map;
        string *ks;
        string msg;
        string str;
        int n;

        ob = this_object();
        me = this_player();

        if (! me->query("out_family"))
                return "�����ϴ��˵�ͼ����ô��";

        if (me->query("map_all"))
                return "��ĵ�ͼ������¼ȫ���ˣ����絽�������߰ɡ�";

        if (! mapp(map = me->query("map")))
                return "Ŷ�����Ȿ��ͼ�ỹȫ�ǰ�ֽ�ء�";

        // �鿴��Щ�ط�û�л���
        ks = (string *) MAP_D->query_all_map_zone() - keys(map);

        if (sizeof(ks) < 1)
        {
                n = 0;
                foreach (str in keys(map))
                        n += sizeof(map[str]);

                if (n < 750)
                {
                        message_sort(HIW "$N" HIW "�ӹ�$n" HIW "�ĵ�ͼ�ᣬ��ϸ"
                                     "����һ�����̾�����ҿ�������Ƶĵ�ͼ����"
                                     "����¼�ص㵹����ȫ�ģ���ϧ�ܶ�ط����ز�"
                                     "�飬���Լ��ú��ٿ����ɡ�\n" NOR, ob, me);
                        return 1;
                }

                message_sort(HIW "$N" HIW "�ӹ�$n" HIW "�ĵ�ͼ�ᣬ��ϸ����һ��"
                             "������˼���ã��ַ�����һ�󣬲��ɵ�ϲ��ü�ң���$n"
                             HIW "�޵�����ʵ�ڲ����뵽�����ϻ�����������һ����"
                             "����ɽ�󴨣��ѵã��ѵá��ţ��ҿ���ĵ�ͼ���л���"
                             "����ȱ©����͸��㲹ȫ�ɣ��պ�������õ��ϡ���"
                             "˵�꣬$N" HIW "��������ʣ���$n" HIW "�ĵ�ͼ����"
                             "���˼��ʣ�������$n" HIW "��\n" NOR, ob, me);

                me->delete("map");
                me->set("map_all", 1);

                CHANNEL_D->do_channel(this_object(), "rumor", "��˵" +
                                      me->name(1) + HIM + "(" + me->query("id") +
                                      ")����ϼ���̵ֽ���ɽ��֪ʶ�����"
                                      "�˵�ͼȫ����" NOR);

                me->add("potential", 5000);
                me->add("score", 3000);
                tell_object(me, HIG "\n����ϸ�����˵�ͼȫ����˼����ã��ջ���"
                                "�ࡣ\nͨ���˴ξ�������������ǧ��Ǳ�ܺ���ǧ"
                                "�㽭��������\n" NOR);
                return 1;
        }

        if (sizeof(ks) > 3) ks = ks[0..2];
        ks = map_array(ks, (: MAP_D->query_map_short($1) :));

        msg = HIC "$N" HIC "�ӹ�$n" HIC "�ĵ�ͼ�ᣬ��ϸ��"
              "��һ�������ü�������ҿ���������������Ƶ�"
              "��ͼ���൱��ȫ�أ�����" + implode(ks, "��") +
              HIC "��û����¼���ڡ�\n" NOR;

        message_sort(msg, ob, me);
        return 1;
}
