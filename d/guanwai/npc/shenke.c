#include <ansi.h>
inherit NPC;

mixed ask_me();

void create()
{
        set_name("�ο�", ({ "shen ke", "shen", "ke" }));
        set("long", "����һ���οͣ������ڹ��⾭Ӫ����Ϊ���С�\n");
        set("age", 65);
        set("combat_exp", 300);
        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("attitude", "friendly");
        set("inquiry", ([
                "���" : (: ask_me :),
                "��ȥ" : (: ask_me :),
        ]));
        setup();
        set("startroom", "/d/beijing/majiu");
        carry_object("/clone/misc/cloth")->wear();
}

mixed ask_me()
{
        object ob, me;
        me = this_player();

        if ((string)me->query("family/family_name") != "�������")
                return "����˭����������ʶ��ô��";

        if (find_object(query("startroom")) != environment())
                return "�����ﻹ���£�����Լ��߻�ȥ�ɡ�";

        command("hehe");
        command("say ��Ȼ��ƽ��ү���ѵ��£�����ô���ܲ��");

        message_sort(HIC "\n����ο�ָ��$N" HIC "��������������"
                     "���ѣ�����Ҫ�ع��⣬���Ҹ����������·�ѻ�ʳ"
                     "ȫ�����ҵ�����һ�����������㡣�����������æ"
                     "�������ǣ���$N" HIC "��������������ȥ��\n"
                     "\n" NOR, me);

        ob = load_object("/d/guanwai/xiaoyuan");
        ob = find_object("/d/guanwai/xiaoyuan");
        me->move("/d/guanwai/xiaoyuan");

        message("vision", HIC "\nԶ��һ������ʻ����������һ��" +
                          me->query("name") + HIC "���������˳�"
                          "����\n\n" NOR, environment(me), ({me}));

        tell_object(me, CYN "\n���Ц������λ" + RANK_D->query_respect(me) +
                        CYN "�Ѿ����ˣ����³��ɡ�\n\n" NOR );
        return 1;

}
