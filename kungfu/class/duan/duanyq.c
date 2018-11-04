#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({"duan yanqing", "duan", "yanqing", "qing"}));
        set("gender", "����");
        set("nickname", HIR "�����ӯ" NOR);
        set("title", "�Ĵ����֮��");
        set("age", 58);
        set("long", @LONG
�������Ĵ����֮�ף��˳ƶ����ӯ�Ķ����졣ֻ
�������������࣬���ϳ����һ����Ƥ��ߣ�ϲ
ŭһ˿��¶������ݳ���˫����ϥ���ϣ�ֻ����Ҹ
�µ������������ȴ�����
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("max_qi", 6000);
        set("max_jing", 4000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 200);
        set("combat_exp", 3000000);
        set("score", 60000);

        set_skill("force", 280);
        set_skill("duanshi-xinfa", 280);
        set_skill("dodge", 240);
        set_skill("tiannan-bu", 240);
        set_skill("cuff", 240);
        set_skill("jinyu-quan", 240);
        set_skill("strike", 240);
        set_skill("wuluo-zhang", 240);
        set_skill("sword", 240);
        set_skill("staff", 240);
        set_skill("duanjia-jian", 240);
        set_skill("finger", 280);
        set_skill("qiantian-zhi", 260);
        set_skill("yiyang-zhi", 280);
        set_skill("parry", 240);
        set_skill("jingluo-xue", 280);
        set_skill("literate", 240);
        set_skill("martial-cognize", 280);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("finger", "yiyang-zhi");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "duanjia-jian");
        map_skill("staff", "yiyang-zhi");

        prepare_skill("finger", "yiyang-zhi");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.die" :),
                (: perform_action, "sword.jing" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
