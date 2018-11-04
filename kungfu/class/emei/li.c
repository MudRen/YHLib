inherit NPC;
inherit F_MASTER;

#include "emei.h"
#include <ansi.h>

mixed ask_back();

void create()
{
        set_name("����ϼ", ({ "li mingxia", "li", "mingxia"}));
        set("long", "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӣ�ƽʱ�����ƹ�һЩ"
                    "���ŵ��ӵ����¡�\n");
        set("gender", "Ů��");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "fighter");

        set("str", 24);
        set("int", 20);
        set("con", 21);
        set("dex", 18);

        set("max_qi", 1600);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("combat_exp", 90000);

        set("inquiry", ([
                "��ɽ" : (: ask_back :),
                "back" : (: ask_back :),
        ]));


        set_skill("force", 120);
        set_skill("emei-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("zhutian-bu", 100);
        set_skill("strike", 80);
        set_skill("sixiang-zhang", 80);
        set_skill("hand", 60);
        set_skill("jieshou-jiushi", 60);
        set_skill("parry", 100);
        set_skill("sword", 120);
        set_skill("emei-jian", 120);
        set_skill("literate", 100);
        set_skill("mahayana", 100);
        set_skill("buddhism", 100);
        set_skill("martial-cognize", 20);

        map_skill("force","emei-xinfa");
        map_skill("hand", "jieshou-jiushi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","sixiang-zhang");
        map_skill("sword","emei-jian");
        map_skill("parry","emei-jian");

        prepare_skill("strike", "sixiang-zhang");

        create_family("������", 4, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "strike.xing" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_back()
{
        object me;

        me = this_player();

        if (find_object(query("startroom")) != environment())
                return "��ʲô�����ң��Ҳ�֪����";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�ǳ��������ѵ���ɽ��Ҫ����̧�㣿";

        if (me->query("age") >= 18)
                return "��˵��ѽ�������ô���˻�Ҫ�Ҵ�����ɽô��";

        command("say �ðɣ�����ͬ�ŵķ��ϣ��Ҿʹ�����ɽ�ɡ�");

        message_vision(HIC "$N" HIC "����$n" HIC "������ɽ������ȥ��\n\n" NOR,
                       this_object(), me);
        tell_object(me, HIY "�����ʡ�����ˣ������Ѿ��ľ����˽𶥡�\n" NOR);

        me->move("/d/emei/jinding");

        message("vision", HIC + name() + HIC "һ������" + me->name() +
                          HIC "�첽����ɽ����ȥ��һ����Ͳ���Ӱ���ˡ�\n" NOR,
                          environment());
        move("/d/emei/jinding");
        me->start_busy();
        call_out("back_to_startroom", 5);
        return 1;
}

void back_to_startroom()
{
        string startroom;

        if (! living(this_object()))
                return;

        if (! stringp(startroom = query("startroom")))
                return;

        if (find_object(startroom) == environment())
                return;

        message_vision(HIC "$N" HIC "ͷҲ���صļ���ææ���ˡ�\n" NOR,
                       this_object());
        move(startroom);
        message_vision(HIC "$N" HIC "�����ǵĸ��˹�����\n" NOR,
                       this_object());
}
