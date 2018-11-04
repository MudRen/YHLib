#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a da", "a", "da" }));
        set("long", @LONG
�˱��񽣷����ױ���ؤ���Ĵ���֮�ף�����
֮��������������ֻ����������죬��������
�߰����ֱ�һ�㣬����ϵ��������š�ʮ��
��ǰ��˵����Ⱦ�ز���������ʱ���˶�����ϧ��
������������������
LONG);
        set("title", "ؤ���Ĵ���֮��");
        set("nickname", WHT "�˱���" NOR);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);        
        set("max_qi", 5800);
        set("max_jing", 5800);
        set("neili", 6200);
        set("max_neili", 6200);
        set("jiali", 250);
        set("combat_exp", 3500000);
        set("score", 500000);

        set_skill("force", 300);
        set_skill("jiaohua-neigong", 280);
        set_skill("huntian-qigong", 300);
        set_skill("dodge", 280);
        set_skill("feiyan-zoubi", 280);
        set_skill("sword", 300);
        set_skill("guanri-jian", 300);
        set_skill("pichen-jian", 300);
        set_skill("parry", 280);
        set_skill("unarmed", 280);
        set_skill("changquan", 280);
        set_skill("staff", 280);
        set_skill("jiaohua-bangfa", 280);
        set_skill("dagou-bang", 280);
        set_skill("strike", 280);
        set_skill("dragon-strike", 280);
        set_skill("begging", 200);
        set_skill("checking", 200);
        set_skill("martial-cognize", 300);

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("sword", "guanri-jian");
        map_skill("parry", "guanri-jian");
        map_skill("unarmed", "changquan");
        map_skill("staff", "dagou-bang");
        map_skill("strike", "dragon-strike");

        prepare_skill("strike", "dragon-strike");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fen" :),
                (: perform_action, "sword.guan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shengang" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object(__DIR__"obj/jian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
