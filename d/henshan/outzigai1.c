#include <ansi.h>
inherit ROOM;

string look_bi(object me,string msg);
void auto_close();

void create()
{
	set("short","ͻʯ��");
	set("long",@LONG
վ�������������ŷ����Լ��Ѿ��������ʮ���ɸ��ˣ�Ѱ
�����ڷ��������䶼��ͻʯ������Ψ�н������������վ����
���������ϸ�۲�ͻʯ��Χ��������ʯ��(bi)�о���һ˿ϸ
С���ѷ죬���������濴���Ĺ������Ǵ����ѷ���Ͷ������ġ�
LONG);
	set("exits",([
	       "down":__DIR__"outzigai",		
	]));

	set("no_fight",1);

	set("item_desc",([
	       "bi":(:look_bi:),
	]));
	
	setup();

}


string look_bi(object me,string msg)
{
	object here;

	me = this_player();

	if ( !here = find_object(__DIR__"outzigai1"))
              here = load_object(__DIR__"outzigai1");
	

	if (here->query_temp("marks/��"))
		return "ʯ���Ѿ��������ˡ�\n";
	
	if (here->query_temp("marks/��"))
		return HIC"\nʯ���Ѿ����ƿ��ˣ�ȴ¶��һ��ɽ������\n"NOR;

	msg="���ʯ�ڿ������ܼ�ʵ��Ҳ�������ڳ��걻ˮ����ʴ��������\n��������"
	    "һ��ϸС���ѷ졣һ˿����ӷ���Ͷ�������������\n��Ӧ���г�·�ˡ�\n";

	return msg;
	          	
}


void init()
{
	object me = this_player();
        object here;
        string msg;

        if ( !here = find_object(__DIR__"outzigai1"))
              here = load_object(__DIR__"outzigai1");
	 
        if (here->query_temp("marks/��"))
        {
       tell_object(me,HIY"���������������ϣ���е�������ˡ�\n"NOR);

       delete("long");
       set("long",HIY @LONG
�㻷�����ܣ������������澹��ʮ���ɸ��ˣ��������
��Ķ������˳�����ʯ����ˮ�鷴���ҫ�۵Ĺ⻷��ͻʯ�ϵ�
��̦Ҳ��"�������͵ģ�����û���˵�����ĳ��졣
LONG);
        }
          
	add_action("do_tiao",({"tiao","jump"}));
	add_action("do_push",({"tui","push"}));
}

int do_tiao(string arg)
{	
	object me = this_player(),ob;

	if ( !ob = find_object(__DIR__"outzigai"))
              ob = load_object(__DIR__"outzigai");
	
	if( !arg || arg != "down")
		return notify_fail("��Ҫ���Ķ�����\n");

	if (me->query_skill("dodge",1) < 120)
	{
	message_vision("\n$N����������������һ��...\n",me);
	me->unconcious();	
	me->move(__DIR__"outzigai");
	tell_room(ob,""+me->name()+"������ˤ���������赹�ˡ�\n");
	return 1;
	}
	
	message_vision("\n$N������һ�������ȵ������˵��ϡ�\n\n",me);
	me->move(__DIR__"outzigai");
	message("vision",""+me->name()+"����������������\n",ob,me);
	return 1;
	
}

int do_push(string arg)
{
	object me = this_player(),obj,obhere;
	string msg;

	if ( !obj = find_object(__DIR__"zigaihole"))
              obj = load_object(__DIR__"zigaihole");

	if ( !obhere = find_object(__DIR__"outzigai1"))
              obhere = load_object(__DIR__"outzigai1");	

	if ( !arg || arg != "bi")
	{
	write("��Ҫ��ʲô��\n");
	return 1;
	}

	if (obhere->query_temp("marks/��"))
	{
	write("ʯ���Ѿ����ƿ��ˡ�\n");
	return 1;
	}
	
	if (me->query("neili") < 1500 || me->query_skill("unarmed",1) < 80)
	{		
	write("��ʹ���������������ʯ�ڣ�����ʯ��ȴ��˿������\n");
	return 1;
	}

	msg = HIC"\n$N������ʯ�����Ա�һ�ƣ��䣡��һ����ʯ���ѱ��ƿ���¶��"NOR;
        msg += HIC"һ��ɽ�������⾹��һ��ʯ�š�\n\n"NOR;

	message_vision(msg,me);

	tell_room(obhere,HIY"���������˽�����ҫ�۶�Ŀ��\n\n"NOR);
	tell_room(obj,HIC"����䣡��һ�����������˽�ʯ���ƿ��ˡ�\n"NOR);

	set("exits/enter",__DIR__"zigaihole");

	obhere->set_temp("marks/��",1);
	obj->set_temp("marks/��",1);
	obj->set("exits/out",__DIR__"outzigai1");

        if (obhere->query_temp("marks/��"))
        {

         delete("long");
       set("long",HIY @LONG
�㻷�����ܣ������������澹��ʮ���ɸ��ˣ��������
��Ķ������˳�����ʯ����ˮ�鷴���ҫ�۵Ĺ⻷��ͻʯ�ϵ�
��̦Ҳ��"�������͵ģ�����û���˵�����ĳ��졣
LONG);
        }

	call_out("auto_close",13);

	return 1;
}

void auto_close()
{
	object obin,obout,me=this_player();

	if ( !obin = find_object(__DIR__"zigaihole"))
              obin = load_object(__DIR__"zigaihole");

	if ( !obout = find_object(__DIR__"outzigai1"))
              obout = load_object(__DIR__"outzigai1");

	tell_room(obin,HIW"\n�䣡�䣡�䣡��֪��˭��ʯ�Ź����ˡ�\n"NOR);
	tell_room(obout,HIW"\n�䣡�䣡�䣡��֪��˭��ʯ�Ź����ˣ���ʱɽ"
                        "����������������\n"NOR);

	delete("exits/enter");
	obin->delete("exits/out");
	obin->delete_temp("marks/��");
	obout->delete_temp("marks/��");

        delete("long");
        set("long",@LONG
վ�������������ŷ����Լ��Ѿ��������ʮ���ɸ��ˣ�Ѱ
�����ڷ��������䶼��ͻʯ������Ψ�н������������վ����
���������ϸ�۲�ͻʯ��Χ��������ʯ��(bi)�о���һ˿ϸ
С���ѷ죬���������濴���Ĺ������Ǵ����ѷ���Ͷ������ġ�
LONG);

	return ;
}





int valid_leave(object me,string dir)
{
	me=this_player();
	
	if(dir=="down")
	        return notify_fail ("������û��·������ֻ������ȥ�ˡ�\n");
	 	
	return 1;

}







