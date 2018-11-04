#include <ansi.h>
inherit ROOM;

string look_bi(object me);

void create()
{
	set("short","��Ȫ��");
	set("long",@LONG
һ��������������Ȫˮ��quanshui��������������ֻ�����Ȫˮ�Ӷ���һ
���䴦ӿ�������Ա�ȴ����һ����bei���� ɽ����ǰ�Ǹ���ʯ�ڣ�bi��������
����ͼ����ʯ����ȴ����һ��ľ����mu jian���� ������������������������
��ɽ��������һ��ʯ����bed�����ɴ˶϶���������������ס����

LONG
);

	set("exits",([
	      "out":__DIR__"xuanyadi",
	]));

	set("item_desc",([
	      "mu jian":"\nһ��ľ������ز���ʯ���У�ֱ���������ɼ������彣֮�˹����ε����ʵ��������\n",
	      "bed":"\nһ�ŷǳ���ª��ʯ��������ȴմ���˻ҳ���\n",
	      "quanshui":"\nһ����ȪԴԴ�شӵ���ӿ����ˮ���峺�������̲�ס���(he)�����ڡ�\n",
	      "bei":"\n���飺"HIR"�� Ȫ ֮ ˮ"NOR" �ַ��پ�������\n",
	      "bi":( : look_bi :),
	]));


	setup();

}

void init()
{
	add_action("do_he","he");
	add_action("do_xue","xue");
	add_action("do_ba","ba");

}

string look_bi(object me)
{
	string msg;	
	int furong,zigai;

	me=this_player();
	furong=me->query_skill("furong-jianfa",1);
	zigai=me->query_skill("zigai-jianfa",1);

	msg=HIC"\n����ϸһ����ʯ���Ͽ�������ֳֳ�����С�ˣ�ÿ�˸�ʹһ�У�ϸ��������һ�׽�����\n"NOR;

	if(zigai&&furong)msg+=HIY"����ϸ��ĥ����Լ�������׽�������[�ϸǽ���]��[ܽ�ؽ���]����ʽ��\n"NOR;
	if(zigai&&!furong)msg+=HIY"����ϸ��ĥ����Լ�������׽���������[�ϸǽ���]����ʽ��\n"NOR;
	if(!zigai&&furong)msg+=HIY"����ϸ��ĥ����Լ�������׽���������[ܽ�ؽ���]����ʽ��\n"NOR;
	msg+=HIC"��Խ��Խ�𾢣��̲�ס�����ѧ(xue)������\n"NOR;
	
	write(msg);
		
	write(@TEXT

  ��>              ��           ��             \  ��	           ��
  \ __           --v|\        \//>---           \//\            --v|^ 
  /<               /<         //> 	          <\              /<          
   								     
[��������]    [Ȫ��ܽ��]    [�����ϸ�]        [���ף��]       [ʯ������]
								     
TEXT         
);


	return "";

}

int do_he(string arg)
{
	object me=this_player();
	
	if(!arg||arg!="quanshui")
		return notify_fail("�����ʲô��\n");

	if(me->is_fighting()||me->is_busy())
		return notify_fail("��������æ���ء�\n");
       
        if(me->query("D_TIANQUAN"))
                return notify_fail("���Ѿ��ȹ���Ȫˮ�ˡ�\n");
	
	me->add("water",200);
	write("�㸩�������һ��Ȫˮ��ֻ����Ȫˮ�����ޱȣ�ƽ����δ������\n");

        me->set("D_TIANQUAN",1);
	
	return 1;
}

int do_xue(string arg)
{
	object me=this_player();
	int furong,zigai,hengshan,cost_qi,cost_neili,cost_jing,lvl_add;
	
	furong=me->query_skill("furong-jianfa",1);
	zigai=me->query_skill("zigai-jianfa",1);
	hengshan=me->query_skill("hengshan-jianfa",1);
	cost_qi=25;
	cost_neili=25;
	cost_jing=10;
	lvl_add=(int)( (me->query_skill("sword",1)+me->query_skill("literate",1))/2);


	if(!arg||(arg!="bi"&&arg!="ʯ��") )return 0;

	if(me->is_fighting()||me->is_busy())
	{
	write("��������æ���ء�\n");
	return 1;
	}
		
	if(!zigai||!furong||!hengshan)
	{
	write("ʯ���ϵĽ������Ǽ��ֽ����ں���һ��ģ��㿴����ȥ����֪���롣\n");
	return 1;
	}

	if(zigai<100||furong<120||hengshan<120)
	{
	write("ʯ���ϵĽ������ƺ�ѧ��һ�㣬���ǻ��ǲ����ڻ��ͨ��\n");	
	return 1;
	}

	if(me->query_skill("literate",1)<300)
	{
	write("Ҳ�����������̫���Ȼѧ������Ľ����������ǽ��䲻���ڻ��ͨ��\n");
	return 1;
	}

	if(me->query("max_neili")<5000)
	{
	write("���������Ϊ̫��޷���ϰʯ���ϵĽ�����\n");
	return 1;
	}

	if(me->query_skill("sword",1)<=me->query_skill("hsws-sword",1))
	{
	write("��Ļ���̫���ˣ�ʯ���ϵĽ���ֻ��ѧ������̶ȡ�\n");
	return 1;
	}

	if(me->query("jing")<=cost_jing)
	{
	write("��ľ����޷����С�\n");
	return 1;
	}

	if(me->query("neili")<=cost_neili)
	{
	write("����������㣬�޷�������ϰ��\n");
	return 1;
	}	

	if(me->query("qi")<=cost_qi+5)
	{
	write("����������㣬�޷�������ϰ��\n");
	return 1;
	}
	
	if(me->query_skill("hsws-sword",1)>=120)
	{
	write("ʯ���ϵĽ�������ȫ�������Ժ�Ϳ��Լ��ڼ���ϰ�ˡ�\n");
	return 1;
	}

	write("��������������ʯ���ϵĽ�����ϰ��һ�飬���ý�������\n");
	me->improve_skill("hsws-sword",lvl_add);
	me->receive_damage("qi",cost_qi);	
	me->receive_damage("jing",cost_jing);
	me->add("neili",-cost_neili);

	return 1;

}


int do_ba(string arg)
{
	object me=this_player(),jian,here;

	if(!here = find_object(__DIR__"tianquan-hole"))here = load_object(__DIR__"tianquan-hole");
	
	if(!arg||(arg!="jian"&&arg!="mu jian"&&arg!="ľ��"))
		return notify_fail("��Ҫ��ʲô��\n");
	
	if(me->query("neili")<5000)
	{
	message_vision(HIG"$N������Ҫ��ľ����ʯ���аγ���������ľ��ȴ��˿������\n"NOR,me);
	return 1;
	}		

	message_vision(HIG"�~����һ����$N�ѽ�ľ����ʯ���а��˳�����\n"NOR,me);

	jian=new(__DIR__"obj/mujian");
	jian->move(me);

	return 1;
}
