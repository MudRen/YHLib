#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�׹���", ({ "bai guishou", "bai", "guishou"}));
        set("long", @LONG
��������ӥ������̳���׹��٣�������ԼĪ��
ʮ���꣬ͺ��ͷ����һ���ʵ�ļ��⡣
LONG);
        set("title", "��ӥ��");
        set("nickname", WHT "����̳��" NOR);
        set("attitude", "heroism");
        set("age", 50);
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 3500);
        set("max_jing", 3500);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 10000);

        set_skill("force", 150);
        set_skill("riyue-xinfa", 150);
        set_skill("dodge", 150);
        set_skill("feiyan-zoubi", 150);
        set_skill("blade", 150);
        set_skill("danding-dao", 150);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("zhenyu-quan", 150);
        set_skill("claw", 150);
        set_skill("poyue-zhao", 150);
        set_skill("martial-cognize", 150);
        set_skill("literate", 100);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "riyue-xinfa");
        map_skill("blade", "danding-dao");
        map_skill("parry", "danding-dao");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("��ӥ��", 2, "̳��");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
                (: exert_function, "recover" :),
                CYN "�׹��ٺȵ����޳�С�������Ҵ������������⣿\n" NOR,
                CYN "�׹�����������̵ģ���Ȼ��������ӥ�̶����ǣ�\n" NOR,
                CYN "�׹����������ɱ�ģ������ү�����������޻أ�\n" NOR,
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object(__DIR__"obj/jiaofu")->wear();
}
