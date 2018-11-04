#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ʯ˫Ӣ", ({ "shi shuangying", "shi", "shuangying" }));
        set("title", "�컨��ʮ������");
        set("nickname", HIR "�����" NOR);
        set("long", "�����ʯ˫Ӣ�ڻ�������ʮ���ѽ��Σ�ִ����\n"
                    "�ã�������˽���ĺ����������˹����ľ�����\n"
                    "�����ĺ��ǣ���Ҳ������ץ�����̣�ԭ������\n"
                    "�컨������������ֵܷ��˴������һʱ��\n"
                    "Ϳ���˺���Ļ��򣬿��ڿ�����ִ��֮ǰ����\n"
                    "���ü⵶�ڴ�����������������������Դ���\n"
                    "��������ν��������������Ȼ����ùܶ�����\n"
                    "ִ��������ˡ���������ᷢ�䣬������������\n"
                    "���Բ�����ˡ�����Ժ컨�������ֵܣ��ᵽ��\n"
                    "����ʱ�޲��Ȼ��\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2500);
        set("max_jing", 2500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 10000);

        set_skill("force", 100);
        set_skill("honghua-xinfa", 100);
        set_skill("unarmed", 100);
        set_skill("changquan", 100);
        set_skill("dodge", 100);
        set_skill("yanzi-chuanyun", 100);
        set_skill("staff", 120);
        set_skill("fengmo-zhang", 120);
        set_skill("parry", 100);
        set_skill("martial-cognize", 60);
        set_skill("literate", 100);

        map_skill("force"  , "honghua-xinfa");
        map_skill("staff"  , "fengmo-zhang");
        map_skill("unarmed" , "changquan");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "fengmo-zhang");

        prepare_skill("unarmed", "changquan");

        create_family("�컨��", 4, "����");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "staff.lun" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �㲻��ͽ���������൱�ҵİɡ�");
}
