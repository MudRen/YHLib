#include <ansi.h>;

inherit KNOWER;
inherit F_DEALER;

#define CONA    "/clone/fam/gift/con1"
#define CONB    "/clone/fam/gift/con2"
#define CONC    "/clone/fam/gift/con3"

#define DEXA    "/clone/fam/gift/dex1"
#define DEXB    "/clone/fam/gift/dex2"
#define DEXC    "/clone/fam/gift/dex3"

#define INTA    "/clone/fam/gift/int1"
#define INTB    "/clone/fam/gift/int2"
#define INTC    "/clone/fam/gift/int3"

#define STRA    "/clone/fam/gift/str1"
#define STRB    "/clone/fam/gift/str2"
#define STRC    "/clone/fam/gift/str3"

#define FOOD    "/clone/fam/pill/food1"
#define FULL    "/clone/fam/pill/full1"

#define HUIA    "/clone/fam/pill/linghui1"
#define HUIB    "/clone/fam/pill/linghui2"

#define NEIA    "/clone/fam/pill/neili1"
#define NEIB    "/clone/fam/pill/neili2"

#define PUTA    "/clone/fam/pill/puti1"
#define PUTB    "/clone/fam/pill/puti2"
#define PUTC    "/clone/fam/pill/puti3"
#define PUTD    "/clone/fam/pill/puti4"

#define SHEA    "/clone/fam/pill/sheli1"
#define SHEB    "/clone/fam/pill/sheli2"
#define SHEC    "/clone/fam/pill/sheli3"
#define SHED    "/clone/fam/pill/sheli4"

#define ZHIA    "/clone/fam/pill/lingzhi1"
#define ZHIB    "/clone/fam/pill/lingzhi2"
#define ZHIC    "/clone/fam/pill/lingzhi3"
#define ZHID    "/clone/fam/pill/lingzhi4"

#define RENA    "/clone/fam/pill/renshen1"
#define RENB    "/clone/fam/pill/renshen2"
#define RENC    "/clone/fam/pill/renshen3"
#define REND    "/clone/fam/pill/renshen4"

#define XUEA    "/clone/fam/pill/xuelian1"
#define XUEB    "/clone/fam/pill/xuelian2"
#define XUEC    "/clone/fam/pill/xuelian3"
#define XUED    "/clone/fam/pill/xuelian4"

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }));
        set("gender", "����" );
        set("age", 22);
        set("long", "��λ��С����Ц�����æ��������ʱ�����"
                    "�ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");

        set("rank_info/respect", "С����");
        set("vendor_goods", ({
                __DIR__"obj/jitui",
                __DIR__"obj/jiudai",
                __DIR__"obj/baozi",
                __DIR__"obj/kaoya",

        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        switch(random(2))
        {
        case 0:
                say(CYN "��С��Ц�����˵������λ" + RANK_D->query_respect(ob) +
                    CYN "�������ȱ��裬ЪЪ�Ȱɡ�\n" NOR);
                break;
        case 1:
                say(CYN "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" +
                    RANK_D->query_respect(ob) + CYN "����������\n" NOR);
                break;
        }
}

int accept_object(object me, object ob)
{
        string name;

        if (base_name(ob) != CONA && base_name(ob) != CONB
           && base_name(ob) != CONC && base_name(ob) != DEXA
           && base_name(ob) != DEXB && base_name(ob) != DEXC
           && base_name(ob) != INTA && base_name(ob) != INTB
           && base_name(ob) != INTC && base_name(ob) != STRA
           && base_name(ob) != STRB && base_name(ob) != STRC
           && base_name(ob) != FOOD && base_name(ob) != FULL
           && base_name(ob) != HUIA && base_name(ob) != HUIB
           && base_name(ob) != NEIA && base_name(ob) != NEIB
           && base_name(ob) != PUTA && base_name(ob) != PUTB
           && base_name(ob) != PUTC && base_name(ob) != PUTD
           && base_name(ob) != SHEA && base_name(ob) != SHEB
           && base_name(ob) != SHEC && base_name(ob) != SHED
           && base_name(ob) != ZHIA && base_name(ob) != ZHIB
           && base_name(ob) != ZHIC && base_name(ob) != ZHID
           && base_name(ob) != RENA && base_name(ob) != RENB
           && base_name(ob) != RENC && base_name(ob) != REND
           && base_name(ob) != XUEA && base_name(ob) != XUEB
           && base_name(ob) != XUEC && base_name(ob) != XUED)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }
        name = base_name(ob);
        me->add("sys/" + ob->name(), 1);
        destruct(ob);

        command("say �ⶫ���������ˣ�������ȥ����ʦ�ðɡ�");

        ob = new("/clone/money/gold");
        ob->move(this_object());
        command("give 1 gold to " + me->query("id"));
        command("say �������������ǻؿۣ����պ��ˡ�");
        return 1;
}
