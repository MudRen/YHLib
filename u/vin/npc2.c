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
        set("long", "��λ��С����Ц�����æ��������ʱ��"
                    "����ڲ����ϵ�Ĩ��������\n");
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
        add_action("do_exchange", "exchange");
        add_action("do_exchange", "duihuan");

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

int do_exchange(string arg)
{
        object ob, me;
        int i, count;
        string name;

        me = this_player();

        if (! me->query("sys"))
                return notify_fail(CYN "��С��������Цһ����û"
                                   "���㡣\n" NOR);

        for (i = 0; i < 38; i++)
        {
	        switch (i)
        	{
        	case 0:
	                name = CONA;
                        break;
        	case 1:
	                name = CONB;
                        break;
        	case 2:
	                name = CONC;
                        break;
        	case 3:
	                name = DEXA;
        	        break;
        	case 4:
	                name = DEXB;
        	        break;
        	case 5:
	                name = DEXC;
        	        break;
        	case 6:
	                name = INTA;
        	        break;
        	case 7:
	                name = INTB;
        	        break;
        	case 8:
	                name = INTC;
        	        break;
        	case 9:
	                name = STRA;
        	        break;
        	case 10:
	                name = STRB;
        	        break;
        	case 11:
	                name = STRC;
        	        break;
        	case 12:
	                name = FOOD;
        	        break;
        	case 13:
	                name = FULL;
        	        break;
        	case 14:
	                name = HUIA;
        	        break;
        	case 15:
	                name = HUIB;
        	        break;
        	case 16:
	                name = NEIA;
        	        break;
        	case 17:
	                name = NEIB;
        	        break;
        	case 18:
	                name = PUTA;
        	        break;
        	case 19:
	                name = PUTB;
        	        break;
        	case 20:
	                name = PUTC;
        	        break;
        	case 21:
	                name = PUTD;
        	        break;
        	case 22:
	                name = SHEA;
        	        break;
        	case 23:
	                name = SHEB;
        	        break;
        	case 24:
	                name = SHEC;
        	        break;
        	case 25:
	                name = SHED;
        	        break;
        	case 26:
	                name = ZHIA;
        	        break;
        	case 27:
	                name = ZHIB;
        	        break;
        	case 28:
	                name = ZHIC;
        	        break;
        	case 29:
	                name = ZHID;
        	        break;
        	case 30:
	                name = RENA;
        	        break;
        	case 31:
	                name = RENB;
        	        break;
        	case 32:
	                name = RENC;
        	        break;
        	case 33:
	                name = REND;
        	        break;
        	case 34:
	                name = XUEA;
        	        break;
        	case 35:
	                name = XUEB;
        	        break;
        	case 36:
	                name = XUEC;
        	        break;
	        default:
	                name = XUED;
        	        break;
	        }
                ob = new(name);

	        if ((count = me->query("sys/" + ob->name())) >= 1
                   || (count = me->query("sys/" + NOR + ob->name())) >= 1)
        	{
                	ob->set_amount(count);
                        tell_object(me, HIC "����ȡ��" + ob->query_amount() + 
                                        HIC "����λ��" + ob->name() +
                                        HIC "��\n" NOR);
                	ob->move(me, 1);
                	me->delete("sys/" + ob->name());
                	me->delete("sys/" + NOR + ob->name());
        	}

        }
        return 1;
}
