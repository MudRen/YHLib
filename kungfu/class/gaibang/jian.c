#include <ansi.h>
#include "gaibang.h"

#define POBU    "/d/gaibang/npc/obj/po-bu"
#define LING    "/d/gaibang/npc/obj/qingzhu-ling"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_me();

void create()
{
        set_name("����", ({ "jian zhanglao", "jian", "zhanglao" }));
        set("long", @LONG
������ؤ���ִ�����ϣ�������ִ�Ʒ�����
��������ȡ�������������𣬵�������˭��
�������־������顣
LONG);
        set("nickname", HIR "ִ������" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 4200);
        set("max_jing", 3500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 180);
        set("combat_exp", 2000000);
        set("score", 500000);
        set("shen_type", 1);

        set_skill("force", 240);
        set_skill("jiaohua-neigong", 220);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("unarmed", 220);
        set_skill("changquan", 220);
        set_skill("jueming-tui", 220);
        set_skill("strike", 220);
        set_skill("tongchui-zhang", 220);
        set_skill("parry", 220);
        set_skill("staff", 240);
        set_skill("jiaohua-bangfa", 220);
        set_skill("fumo-zhang", 220);
        set_skill("begging", 260);
        set_skill("checking", 260);
        set_skill("literate", 200);
        set_skill("martial-cognize", 200);

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "jueming-tui");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "fumo-zhang");
        map_skill("staff", "fumo-zhang");
        map_skill("strike", "tongchui-zhang");

        prepare_skill("strike", "tongchui-zhang");
        prepare_skill("unarmed", "jueming-tui");

        create_family("ؤ��", 18, "�Ŵ�����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.kai" :),
                (: perform_action, "unarmed.jue" :),
                (: perform_action, "staff.lun" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "������" : (: ask_me :)
        ]));

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/d/gaibang/npc/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �Ϸ���ͽ�ܣ��㻹����ذɡ�");
}

mixed ask_me()
{
        object ob, me;
        int lvl, gx;

        me = this_player();

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����뱾��������������֪�˻��Ӻ�̸��";

        if (me->query("combat_exp", 1) < 10000)
                return "�ٺ٣������㱾��Ҳ����˼��Ҫ�����";

        lvl = me->query("family/beggarlvl");

        if (lvl >= 9)
                return "���Ѿ��Ǳ��ﳤ���ˣ��ֺ�ȥ�����Ǽƽϡ�";

        if (lvl <= 0)
                gx = 100;
        else
                gx = lvl * 100 + 200;

        if (me->query("gongxian") < gx)
                return "��Ϊ����Ч����������ʱ���ܸ���������";

        if (present("qingzhu ling", me))
                return "�����ϲ����Ѿ�������������";

        if (time() - me->query_temp("have_ling") < 100)
                return "�Ҳ��ǸողŸ�����һ������΢�Ȼ�ɡ�";

        ob = new(LING);
        ob->move(this_object());

        command("give qingzhu ling to " + me->query("id"));
        me->set_temp("have_ling", time());

        return "ƾ���������������������ͬ�Ŵ�ʦ����ս��";
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        int r;
        int lvl, exp, pot, sc, ww, gx;
        string msg;

        if (r = ::accept_object(ob, obj))
                return r;

        if (base_name(obj) != POBU)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (obj->query("owner") != ob->name())
        {
                command("say ������Ʋ��Ǵ�����͵���ģ�");
                return 0;
        }

        if (ob->query_temp("have_cloth") < 1)
        {
                command("say �������ʤ��ô������ô��û��˵��");
                return 0;
        }

        lvl = ob->query("family/beggarlvl");

        if (lvl >= 9)
        {
                command("say ���Ѿ��Ǳ��ﳤ���ˣ����뵱������");
                return 0;
        }

        if (lvl <= 0)
                gx = 100;
        else
                gx = lvl * 100 + 200;

        if (ob->query("gongxian") < gx)
        {
                command("say �������Ϊ����Ч����������ʱ���ܸ���������");
                return 0;
        }

        ob->add("family/beggarlvl", 1);
        ob->set("title", ob->query_temp("newtitle"));
        ob->delete_temp("have_cloth");
        ob->delete_temp("newtitle");

        message_vision(HIY "\n$N" HIY "�ӹ����Ʋ���Ȼ���䶤"
                       "��$n" HIY "�����·��ϣ�ٲȻһ���¿ڴ�"
                       "��\n\n" NOR, me, ob);
        command("nod");
        command("say ��Ȼ�������͵��μǰ�棬Ϊ�������");

        lvl = lvl + 1;
        exp = lvl * 600 + random(lvl * 400);
        pot = lvl * 300 + random(lvl * 200);
        sc = lvl * 80 + random(lvl * 50);
        ww = lvl * 50 + random(lvl * 30);

        ob->add("combat_exp", exp);
        ob->add("potential", pot);
        ob->add("score", sc);
        ob->add("weiwang", ww);
        ob->add("gongxian", -gx);

        msg = HIC "\nͨ�������ľ�����������" +
              chinese_number(exp) + "�㾭�顢" +
              chinese_number(pot) + "��Ǳ�ܡ�" +
              chinese_number(sc) + "�㽭�������Լ�" +
              chinese_number(ww) + "�㽭��������ͬʱ"
              "������" + chinese_number(gx) + "����"
              "�ɹ��ף���ѧ�õ��˾�����\n\n" NOR;

        tell_object(ob, sort_string(msg, 54));
        ob->improve_skill("martial-cognize", 1500000);

        destruct(obj);
        return 1;
}

void unconcious()
{
        die();
}
