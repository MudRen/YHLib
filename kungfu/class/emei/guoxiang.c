inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
        set_name("����", ({ "guo xiang", "guo", "xiang"}));
        set("long", @LONG
�����Ƕ����ɵĿ�ɽ��ʦ���壬�ˡ���������
���Ķ�Ů�����˳ơ�С��а����
LONG);
        set("title", "�����ɿ�ɽ��ʦ");
        set("nickname", HIY "С��а" NOR);
        set("gender", "Ů��");
        set("age", 21);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 7000);
        set("max_jing", 6000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 250);
        set("combat_exp", 5000000);

        set_skill("force", 320);
        set_skill("emei-xinfa", 300);
        set_skill("emei-jiuyang", 320);
        set_skill("linji-zhuang", 320);
        set_skill("dodge", 300);
        set_skill("zhutian-bu", 300);
        set_skill("finger", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("hand", 300);
        set_skill("jieshou-jiushi", 300);
        set_skill("strike", 320);
        set_skill("jinding-zhang", 300);
        set_skill("piaoxue-zhang", 320);
        set_skill("sixiang-zhang", 300);
        set_skill("sword", 320);
        set_skill("huifeng-jian", 320);
        set_skill("emei-jian", 300);
        set_skill("blade", 300);
        set_skill("yanxing-dao", 300);
        set_skill("parry", 300);
        set_skill("martial-cognize", 300);
        set_skill("literate", 280);
        set_skill("mahayana", 300);
        set_skill("buddhism", 300);

        map_skill("force", "emei-jiuyang");
        map_skill("dodge", "zhutian-bu");
        map_skill("finger", "tiangang-zhi");
        map_skill("hand", "jieshou-jiushi");
        map_skill("strike", "piaoxue-zhang");
        map_skill("sword", "huifeng-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");

        prepare_skill("strike", "piaoxue-zhang");

        create_family("������", 0, "��ɽ��ʦ");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.yun" :),
                (: perform_action, "strike.zhao" :),
                (: exert_function, "recover" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
        }));

        setup();

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ���㻹���ұ��˰ɡ�");
        return;
}
