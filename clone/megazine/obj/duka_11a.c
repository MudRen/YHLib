inherit ITEM;
#include <ansi.h>
string qd="�����";//�����
int peis=2,peig=0;//���� peis��peig��ʾ����peis.peig
//������UPDATE�ļ�

void create()
{
        set_name(HIC"����A-�����" NOR, ({ "it ka","ka", }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIY 
       "���Ŷ�������д��:" + qd + "Ӯ\n"
        "��ֵ��10 cash ����:" + peis + "." + peig +"\n"
        "ʹ��˵����������������12���ʹ��(changeka)���öһ�֧Ʊ��B��\n"
        "����ڴ�ǰ�����������ܶһ��������Լ�����\n"  NOR
       );
                set("value", 1000000);
                set("material", "silk");
                set("no_sell",1);
                set("no_pawn",1);
        }
}

void init()
{
	if(this_player() == environment() )
	{
		add_action("do_changeka","changeka");	
	}
}

int do_changeka()
{
	object ob=this_object();
	object me=this_player();
	object qk;

        qk=new("/clone/megazine/obj/duka_11b");
	qk->move(me);
	message_vision(HIC "$N�Ѷ��򿨻��ˡ�\n" NOR,me);
	destruct(ob);
	return 1;
}

int query_autoload() { return 1; }
