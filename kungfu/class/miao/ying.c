#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����Ӣ", ({ "zhong zhaoying", "zhong", "zhaoying", "ying" }));
        set("long", @LONG
�������������۵��϶�����Ӣ��ֻ��������
ɫ���鲼�·�����ñ��Ь���·�����¶��ëͷ��
���Ǹ����˸�ĸ��Т�ӷ�ɫ����ɫ�Ұף�����
�ֱ��ִ󣬱ǿ׳��죬���źں��ӡ�
LONG );
        set("nickname", HIR "��������" NOR);
        set("title", "���������ֵ�");
        set("gender", "����");
        set("age", 43);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 2600);
        set("max_neili", 2600);
        set("jiali", 80);
        set("combat_exp", 800000);
        set("score", 3000);

        set_skill("force", 150);
        set_skill("xueshan-neigong", 150);
        set_skill("dodge", 150);
        set_skill("feiyan-zoubi", 150);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("yanqing-quan", 150);
        set_skill("staff", 150);
        set_skill("suoming-zhang", 150);
        set_skill("literate", 120);
        set_skill("martial-cognize", 150);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("cuff", "yanqing-quan");
        map_skill("staff", "suoming-zhang");
        map_skill("parry", "suoming-zhang");

        prepare_skill("cuff", "yanqing-quan");

        create_family("��������", 6, "����");

        setup();

        carry_object("/d/zhongzhou/npc/obj/kusang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 15);
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �߿����Ҳ���ͽ��");
}
