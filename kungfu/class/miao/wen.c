#include <ansi.h>

inherit NPC;
inherit F_GUARDER;

void create()
{
        set_name("������", ({ "zhong zhaowen", "zhong", "zhaowen", "wen" }));
        set("long", @LONG
�������������۵��ϴ������ġ�ֻ��������
ɫ���鲼�·�����ñ��Ь���·�����¶��ëͷ��
���Ǹ����˸�ĸ��Т�ӷ�ɫ����ɫ�Ұף�����
�ֱ��ִ󣬱ǿ׳��죬���ŻҰ�С���ӡ�
LONG );
        set("nickname", HIR "��������" NOR);
        set("title", "���������ֵ�");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);

        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 80);
        set("combat_exp", 800000);
        set("score", 3000);

        set_skill("force", 160);
        set_skill("xueshan-neigong", 160);
        set_skill("dodge", 160);
        set_skill("feiyan-zoubi", 160);
        set_skill("parry", 160);
        set_skill("cuff", 160);
        set_skill("liuhe-quan", 160);
        set_skill("staff", 160);
        set_skill("suoming-zhang", 160);
        set_skill("literate", 140);
        set_skill("martial-cognize", 160);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("cuff", "liuhe-quan");
        map_skill("staff", "suoming-zhang");
        map_skill("parry", "suoming-zhang");

        prepare_skill("cuff", "liuhe-quan");

        set("coagents", ({
                ([ "startroom" : "/d/zhongzhou/miaojia_houting",
                   "id"        : "miao renfeng" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��Ц����"
                                "ʲô�ˣ���Ȼ��������ĸ�ۡ������"
                                "����" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�������ʲô�ˣ�����������"
                                "���£�" NOR,
        ]));

        create_family("��ԭ���", 6, "����");

        setup();

        carry_object("/d/zhongzhou/npc/obj/lingpai")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 15);
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �߿����Ҳ���ͽ��");
}
