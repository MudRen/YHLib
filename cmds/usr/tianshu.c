#pragma save_binary


//begin select xiansuo renwu wanchen status bigreward

#include <ansi.h>
inherit F_CLEAN_UP;
#define XIANSUO "/quest/"
#define XIANSUOO "/quest/"
void select(object me);
void xiansuo(object me);
void get_num(string arg,object me);
void renwu(object me);
void check_corpse(object me);
void nextstep(object me);
void check(object me);
void check_thing(object me);
void check_baohu(object me);
void baohu(object me,object vic);
void reward(int exp,object me);
void status(object me);
string wan(int i);
void bigreward(object me);
void check_song(object me);
void songwu(object me);

int main(object me, string arg)
{
        object aaa, ob, env;
        int i, j, j1, j2;
        string id, name;

	if (! arg)
	{
		if (! me->query("tianshu"))
			return notify_fail("������û�����������\n");
        	else
		if (me->query(me->query("tianshu")))
			return notify_fail("�����ڸ�����"+me->query("tianshu")+"��\n");
        	else
		{
			tell_object(me,"��Ŀǰ�����"+me->query("tianshu")+"��\n");
			return 1;
		}
	}
	if (arg=="begin")
       	{
/*
	        if (! me->query_temp("begin"))
			return 1;
*/
	        if (! me->query("tianshu"))
                {
			tell_object(me,"�㿪ʼ�������ˣ�\n");
	                me->set("tianshu","�ɺ��⴫");
        	        me->set("tianfile","tianshu0");
                	me->delete("xiansuo");
	                me->delete("��Ը");
        	        me->delete("����");
                	me->delete("bu");
	                me->delete("told");
        	        return 1;
		} else
		{
                	tell_object(me,"�㿪ʼ����"+me->query("tianshu")+"�ˣ�\n");
	                me->delete(me->query("tianshu"));
        	        me->delete("xiansuo");
                	me->delete("��Ը");
	                me->delete("bu");
        	        me->delete("����");
                	me->delete("told");
        	        return 1;
		}
        }
	if (arg == "newbegin" && me->query_temp("newbegin"))
	{
               me->delete(me->query("tianshu"));
                me->delete("xiansuo");
                me->delete("��Ը");
                me->delete("told");
                me->delete("����");
                return 1;
	}

	if (arg=="select")
	{
		select(me);
		return 1;
	}
	if (arg=="xiansuo")
	{
		xiansuo(me);
		return 1;
	}
	if (arg=="renwu")
	{
		renwu(me);
		return 1;
	}
	if (arg=="wancheng")
	{
		check(me);
		return 1;
	}
	if (arg=="songwu")
	{
		songwu(me);
		return 1;
	}
	if (arg=="status")
	{
		status(me);
		return 1;
	}
	if (arg=="bigreward")
	{
		bigreward(me);
		return 1;
	}
	tell_object(me,"����help tianshu�������ļ���help exp�������ļ���\n");
	return 1;
}

void select(object me)
{
        if (!me->query_temp("select"))
		return;

        write(" �����ɣ���ѩ�����������죴���䣵���ף�����¹
                ����Ц�����飹����ᣮ���⣮�У㣮�̣��䣮ԧ\n");
        write("��ѡ��0��1��2��3����������");
        input_to("get_num",me);
}

void get_num(string arg,object me)
{
        string s; 
       	if (arg == "" )
	{
                write("��ѡ��0��1��2��3����������");
                input_to("get_num",me);
                return;
        }
        if( arg[0]=='0')
        {
		me->set("tianshu","�ɺ��⴫");
		s="0";
	}
        else if (arg[0]=='1') {me->set("tianshu","ѩɽ�ɺ�");s="1";}
        else if (arg[0]=='2') {me->set("tianshu","���Ǿ�");s="2";}
        else if (arg[0]=='3') {me->set("tianshu","�����˲�");s="3";}
        else if (arg[0]=='4') {me->set("tianshu","���Ӣ�۴�");s="4";}
        else if (arg[0]=='5') {me->set("tianshu","����Х����");s="5";}
        else if (arg[0]=='6') {me->set("tianshu","¹����");s="6";}
        else if (arg[0]=='7') {me->set("tianshu","Ц������");s="7";}
        else if (arg[0]=='8') {me->set("tianshu","�齣����¼");s="8";}
        else if (arg[0]=='9') {me->set("tianshu","�������");s="9";}
        else if (arg[0]=='a') {me->set("tianshu","������");s="a";}
        else if (arg[0]=='b') {me->set("tianshu","����������");s="b";}
        else if (arg[0]=='c') {me->set("tianshu","��Ѫ��");s="c";}
        else if (arg[0]=='d') {me->set("tianshu","ԧ�쵶");s="d";}
     	else {
               	write("�Բ�����ֻ�ܴӣ�0,1,2,3����������ѡ�� ");
              	input_to("get_num",me);
                return;
        }
        tell_object(me,"�������ʼ��"+me->query("tianshu")+"�ˡ�\n");
        me->delete("xiansuo");
        me->delete("��Ը");
        me->delete("����");
        me->delete("bu");
        me->delete("told");
        me->set("tianfile","tianshu"+s);
        return;
}

void xiansuo(object me)
{
        string file, *lines, xiansuo, *words;
        object *inv, env;
        int i, j=-1;

        if (! me->query_temp("dating"))
		return;

	if (! me->query("tianshu"))
	{
		tell_object(me,"��û�����κ��й��������Ϣ��\n");
		return;
	}

        if (me->query(me->query("tianshu")))
	{
		tell_object(me,"���Ѿ������"+me->query("tianshu")+"��"
                               "����select��ѡ����begin�ؿ���\n");
		return;
	}

	if (!me->query("tianfile"))
	{
		tell_object(me,"��û�����κ��й��������Ϣ��\n");
		return;
	}

	if (me->query("combat_exp") > 10000000 && ! random(4))
	{
		file=read_file(XIANSUOO+me->query("tianfile"));
        	lines=explode(file,"\n");

	        if (! me->query("xiansuo")) 
                {
               		xiansuo=lines[random(sizeof(lines))];
               		words=explode(xiansuo,"/");
               		me->set("����",words);
               		me->set("xiansuo",words[0]);
                }
	} else
	{
       		file=read_file(XIANSUO+"xiansuolist");
       		lines=explode(file,"\n");

       		if (!me->query("xiansuo"))
		{
			xiansuo=lines[random(sizeof(lines))];
			me->set("xiansuo",xiansuo);
        	}
	}

	env=environment(me);
	inv=all_inventory(env);
       	i=sizeof(inv);

	while(i--)
        {
       		if (inv[i]->query("name")==me->query("xiansuo")	&& !userp(inv[i]))
			j=i;
	}

	if (j<0)
	        tell_object(me,"Ŀǰ�ƺ�"+me->query("xiansuo")+"�Ƕ���Щ������\n");
	else 
        {
       		if (me->query("told"))
		{
			tell_object(me,inv[j]->name()+"˵�������Ѿ�˵���ˡ�\n");
		} else
		{
			tell_object(me, inv[j]->name()+"˵������֪��" +
				        me->query("tianshu")+"���Ķ���"
					"�������ɼ����������ٸ����㡣\n");
	               	me->set_temp("giverenwu",1);
			me->set("told",1);
		}
        }               
	return;
}

void renwu(object me)
{
        string shu,tasklist,file,*lines,task,*words;
        mapping sss=(["class":"kill","name":"ren","exp":1]);
        object env,*inv,ob;
        int i,j=-1,level,size,up,down;

        if (!me->query_temp("renwu"))
		return;

	if (!me->query_temp("giverenwu")) 
	{
        	sss=me->query("��Ը");
	        if (sss)
        	{
			if (sss["class"]=="kill")
				tell_object(me, "��Ŀǰ���񣺰�"+me->query("xiansuo")+
						"ɱ��"+sss["name"]+"��\n");
	                else
			if (sss["class"]=="find")
				tell_object(me, "��Ŀǰ���񣺰�"+me->query("xiansuo")+
						"�ҵ�"+sss["name"]+"��\n");
	                else
			if (sss["class"]=="song")
				tell_object(me, "��Ŀǰ���񣺰�"+me->query("xiansuo")+
						"��"+me->query("target")+"�͵�"+sss["name"]+"���С�\n");
	                else
			if (sss["class"]=="baohu")
				tell_object(me,"��Ŀǰ���񣺱���"+me->query("xiansuo")+"��\n");
       		} else
			tell_object(me,"��Ŀǰû�����񣬻����ȴ�̽һ��������\n");
	} else
	{
        	env=environment(me);
	        inv=all_inventory(env);
       		i=sizeof(inv);

	        while(i--)
       		{
        	        if (inv[i]->query("name")==me->query("xiansuo")&&!userp(inv[i]))
			j=i;
        	}

		if (j<0)
	        {
			tell_object(me,"���˭˵����\n");
			return;
		}

		if (me->query("����")) 
       	        {
        	        words=me->query("����");
       	        	switch(words[1])
			{
       	                case "kill":tell_object(me,me->query("xiansuo")+"˵���������ɱ��"+words[2]+"������ʬ�������ң�\n");
                                    tell_object(me,me->query("xiansuo")+"˵����"+words[3]+"\n");
                                    sss["class"]="kill";sscanf(words[4],"%d",sss["exp"]);sss["name"]=words[2];
                                    break;

        	        case "find":tell_object(me,me->query("xiansuo")+"˵����������ҵ�"+words[2]+"��\n");
                                    tell_object(me,me->query("xiansuo")+"˵����"+words[3]+"\n");
                                    sss["class"]="find";sscanf(words[4],"%d",sss["exp"]);sss["name"]=words[2];
                                    break;

               	 	case "song":tell_object(me,me->query("xiansuo")+"˵��������Ұ�"+words[3]+"�͵�"+words[2]+"���У�\n");
                                    tell_object(me,me->query("xiansuo")+"˵����"+words[4]+"\n");
                                    sss["class"]="song";sscanf(words[5],"%d",sss["exp"]);sss["name"]=words[2];
                                    me->set("target",words[3]);
                                    ob=new("/obj/tianshu/wupin");
                                    ob->move(me);
                                    ob->set("name",words[3]);
                                    break;
                       	}
                	me->set("��Ը",sss);
       	        	me->delete_temp("giverenwu");
               	} else
		{
			tasklist="/quest/tasklist1";
			file=read_file(tasklist);
			lines=explode(file,"\n");
			level=me->query("combat_exp")/1000000;
			size=sizeof(lines)/10;
			down=size*level*3/2;
			up=down+size;

			if (down<0)
				down=0;

			if (up>=sizeof(lines))
			{
				up=sizeof(lines);
				down=up-size;
			}

			if (!random(5))
			{
				task = lines[random(up)];
			} else
				task = lines[down+random(size)];

			if (sscanf(task,"%s/%s/%d",sss["class"],sss["name"],sss["exp"])!=3)
				return;

			me->set("��Ը",sss);

			if (sss["class"]=="kill")
				tell_object(me, me->query("xiansuo")+
                                                "˵���������ɱ��"+sss["name"]+
                                                "������ʬ�������ң�\n");
			else
			if (sss["class"]=="find")
				tell_object(me, me->query("xiansuo")+"˵�������"
						"���ҵ�"+sss["name"]+"��\n");
			else
			if (sss["class"]=="baohu")
			{
				tell_object(me, me->query("xiansuo")+"˵��������"
						"Ҫ�Ը��ң����������ﱣ���ң�\n");
				call_out("baohu",10,me,inv[j]);
			}
			me->delete_temp("giverenwu");
		}
	}

	if (me->query("wancheng"))
		tell_object(me,"����������ˣ�ûȥ������\n");
}

void check_corpse(object me)
{
        object *inv,env;int i,j=-1;
        mapping renwu;
        renwu=me->query("��Ը");
        env=environment(me);
        inv=all_inventory(env);
        i=sizeof(inv);

        while(i--)
        {
                if (inv[i]->query("name") == me->query("xiansuo") && ! userp(inv[i]))
			j=i;
        }

	if (j<0)
        {
		tell_object(me,"���˭˵����\n");
			return;
	}
        j=-1;

        inv=all_inventory(me);
        i=sizeof(inv);

        while(i--)
        {
                if (inv[i]->query("name")==(me->query("��Ը"))["name"]+"��ʬ��")
			j=i;
        }

        if (j>=0)
	{
		tell_object(me, me->query("xiansuo")+"˵�����ܺã����Ѿ�����ɱ��"+
				(me->query("��Ը"))["name"]+"��\n");
                destruct(inv[j]);

                if (me->query("bu"))
			me->add("bu",1);
                else
			me->set("bu",1);
                reward(renwu["exp"],me);
                me->delete("��Ը");
                me->delete("����");
                nextstep(me);
        } else
	{
                tell_object(me, me->query("xiansuo")+"˵������Ҫ�����ɱ��"+
                                (me->query("��Ը"))["name"]+"���㻹û��ɣ�\n");
	}
}

void nextstep(object me)
{
        int exp;
        string file,*lines,xiansuo,*words;
        object ob;
        if (me->query("bu")>=random(3)+9) 
                {
me->set("end_time",time());
                tell_object(me,me->query("xiansuo")+"˵�����������һ�����飬����������ã���͸���ɡ�\n");
                me->set(me->query("tianshu"),1);
if (me->query(me->query("tianshu")+"s")) me->add(me->query("tianshu")+"s",1);
                        else me->set(me->query("tianshu")+"s",1);
                me->delete("xiansuo");
                me->delete("����");
                me->delete("��Ը");
                me->delete("bu");
                me->delete("told");
exp=400 + me->query("combat_exp")/3000+random(me->query("combat_exp")/3000);
if (exp<300) exp=300;
reward(exp,me);         
                ob=new("/obj/tianshu/"+me->query("tianfile"));
                ob->set("endname",me);
                ob->move(me);
}       
                else {
if (me->query("combat_exp")>10000000&&!random(4))
//if (me->query("combat_exp")<2000000)
switch(random(1)){
case 0: file=read_file(XIANSUOO+me->query("tianfile"));
        lines=explode(file,"\n");
                xiansuo=lines[random(sizeof(lines))];
                words=explode(xiansuo,"/");
                me->set("����",words);
                me->set("xiansuo",words[0]);
        break;
                }
else{
        file=read_file(XIANSUO+"xiansuolist");
        lines=explode(file,"\n");
        xiansuo=lines[random(sizeof(lines))];
        me->set("xiansuo",xiansuo);
        }
        tell_object(me,"��ȥ��"+me->query("xiansuo")+"���ʣ�������û��ʲô��Ϣ��\n");
        me->delete("told");
                        }
}
void check(object me)
{       
        mapping renwu;
        if (!me->query_temp("jiaochai")) return;
if (!me->query("��Ը")) {tell_object(me,"��Ŀǰ���������㻹��������������\n");return;}
renwu=me->query("��Ը");
if (renwu["class"]=="kill") check_corpse(me);
        else if (renwu["class"]=="find") check_thing(me);
        else if (renwu["class"]=="song") check_song(me);
        else if (renwu["class"]=="baohu") check_baohu(me);
}
void check_thing(object me)
{
        object *inv,env;int i,j=-1;
        mapping renwu;
        renwu=me->query("��Ը");
        env=environment(me);
        inv=all_inventory(env);
        i=sizeof(inv);
        while(i--)
        {

                if (inv[i]->query("name")==me->query("xiansuo")&&!userp(inv[i])) j=i;
        }
if (j<0)        {tell_object(me,"���˭˵����\n");return;}
        j=-1;
        inv=all_inventory(me);
        i=sizeof(inv);
        while(i--)
        {
                if (inv[i]->query("name")==(me->query("��Ը"))["name"]) j=i;
        }
        if (j>=0) {tell_object(me,me->query("xiansuo")+"˵�����ܺã����Ѿ������ҵ�"+(me->query("��Ը"))["name"]+"�ˡ�\n");
                        destruct(inv[j]);
                if (me->query("bu")) me->add("bu",1);
                                else me->set("bu",1);
                        me->delete("��Ը");
                        me->delete("����");
                        reward(renwu["exp"],me);
                        nextstep(me);
                        }
        else {
                tell_object(me,me->query("xiansuo")+"˵������Ҫ������ҵ�"+(me->query("��Ը"))["name"]+"���㻹û��ɣ�
\n");
}
}
void baohu(object me,object vic)
{
object obj;
me->set("baohuren",me->query("xiansuo"));
obj->move(environment(me));
obj->set("kill",me->query("xiansuo"));
message_vision("$N���˽���������ؿ���$n��\n",obj,vic);
message_vision("$N��$n�ȵ�������������ã�ԭ����������ȥ���ɣ�\n",obj,vic);
obj->set("combat_exp",me->query("combat_exp")+random(1000000));
vic->set("kee",3000);
obj->kill_ob(vic);
me->kill_ob(obj);
vic->kill_ob(obj);
obj->check();
}
void check_baohu(object me)
{
        object *inv,env;int i,j=-1;
        mapping renwu;
        renwu=me->query("��Ը");
        env=environment(me);
        inv=all_inventory(env);
        i=sizeof(inv);
        while(i--)
        {
                if (inv[i]->query("name")==me->query("xiansuo")&&!userp(inv[i])) j=i;
        }
if (j<0)        {tell_object(me,"���˭˵����\n");return;}
if (me->query("baohuren")) {tell_object(me,me->query("xiansuo")+"˵������Ҫ�㱣���ҡ��㻹û��ɣ�\n");return;}
if (!me->query("baohu")) {tell_object(me,me->query("xiansuo")+"˵������Ҫ�㱣���ҡ����������\n");return;}
        else {tell_object(me,me->query("xiansuo")+"˵�����ܺã����Ѿ��������ҡ�\n");
                        me->delete("baohu");
                if (me->query("bu")) me->add("bu",1);
                                else me->set("bu",1);
                        me->delete("��Ը");
                        me->delete("����");
                        reward(renwu["exp"],me);
                        nextstep(me);
                        }
}
void check_song(object me)
{
        object *inv,env;int i,j=-1;
        mapping renwu;
        renwu=me->query("��Ը");
        env=environment(me);
        inv=all_inventory(env);
        i=sizeof(inv);
        while(i--)
        {
                if (inv[i]->query("name")==me->query("xiansuo")&&!userp(inv[i])) j=i;
        }
if (j<0)        {tell_object(me,"���˭˵����\n");return;}
if (!me->query("wancheng")) {tell_object(me,me->query("xiansuo")+"˵������Ҫ������Ͷ��������������\n");return;}
        else {tell_object(me,me->query("xiansuo")+"˵�����ܺã����Ѿ���������ˡ�\n");
                        me->delete("wancheng");
                if (me->query("bu")) me->add("bu",1);
                                else me->set("bu",1);
                        me->delete("��Ը");
                        me->delete("����");
                        reward(renwu["exp"],me);
                        nextstep(me);
                        }
}
void songwu(object me)
{
        object env,*inv,wu;
        int i,j;
        mapping renwu;
        if (!me->query_temp("song")) return;
        env=environment(me);
        inv=all_inventory(env);
        renwu=me->query("��Ը");
        if (!renwu) {tell_object(me,"��Ŀǰû������\n");return;}
        i=sizeof(inv);
        j=-1;
        while(i--)
        {
                if (inv[i]->query("name")==renwu["name"]&&!userp(inv[i])) j=i;
        }
if (j<0)        {tell_object(me,"��Ӧ�ð�"+me->query("target")+"�͸�"+renwu["name"]+"\n");return;}
        wu=present("wu pin",me);
if (!wu) {
        tell_object(me,"��Ѷ���Ū���Ķ�ȥ�ˣ�\n");return;
}
        if (wu->query("name")==me->query("target")) 
        {
        tell_object(me,renwu["name"]+"Ц��Ц��˵����лл�㣡\n");
        tell_object(me,"�����������ˣ���ȥ����ɡ�\n");
        me->set("wancheng",1);
        destruct(wu);
        return;
        }
        else {tell_object(me,renwu["name"]+"������ü˵������������԰ɡ�\n");return;
}
}
void reward(int exp,object me)
{
    int pot,score;
if(exp>300){
     exp = 600+to_int(sqrt(to_float(me->query("combat_exp"))))+random(1500);
    score = 15+random(30);
    pot = exp/8;
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->add("score",score);
    tell_object(me,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+ 
        chinese_number(score) + "������\n"NOR);
}
else{
                exp=exp*me->query_kar()/20;
                exp+=random(exp);
                pot=exp/8;
                me->add("combat_exp",exp);
                me->add("potential",pot);
                tell_object(me,HIW"�㱻�����ˣ�\n" +
                chinese_number(exp) + "��ʵս����\n"+
                chinese_number(pot) + "��Ǳ��\n"NOR);
}
}
void status(object me)
{
        string line;
        if (!me->query_temp("status")) return;
        line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(me), me->short(1) );
        line += sprintf(" �ɺ��⴫��\t%s\t\tЦ��������\t%s\n"
                        " ѩɽ�ɺ���\t%s\t\t�齣����¼��\t%s\n"
                        " ���Ǿ���\t%s\t\t������£�\t%s\n"
                        " �����˲���\t%s\t\t�����У�\t%s\n"
                        " ���Ӣ�۴���\t%s\t\t���������ǣ�\t%s\n"
                        " ����Х���磺\t%s\t\t��Ѫ����\t%s\n"
                        " ¹���ǣ�\t%s\t\tԧ�쵶��\t%s\n",
                        wan(me->query("�ɺ��⴫")),     
                        wan(me->query("Ц������")),     
                        wan(me->query("ѩɽ�ɺ�")),     
                        wan(me->query("�齣����¼")),   
                        wan(me->query("���Ǿ�")),       
                        wan(me->query("�������")),     
                        wan(me->query("�����˲�")),     
                        wan(me->query("������")),       
                        wan(me->query("���Ӣ�۴�")),   
                        wan(me->query("����������")),   
                        wan(me->query("����Х����")),   
                        wan(me->query("��Ѫ��")),       
                        wan(me->query("¹����")),       
                        wan(me->query("ԧ�쵶")));
        write(line);
        return;
}

string wan(int i)
{
	if (i)
		return HIY"�����"NOR ;
	else
		return "δ���";
}
void bigreward(object me)
{
        object obj;
        if (me->query("�ɺ��⴫")&&
        me->query("Ц������")&&
        me->query("ѩɽ�ɺ�")&& 
        me->query("�齣����¼")&&
        me->query("���Ǿ�")&&
        me->query("�������")&&
        me->query("�����˲�")&&
        me->query("������")&&
        me->query("���Ӣ�۴�")&&
        me->query("����������")&&
        me->query("����Х����")&&
        me->query("��Ѫ��")&&
        me->query("¹����")&&
        me->query("ԧ�쵶")) 
                {
                obj=new("/obj/tianshu/hongbao");
                obj->move(me);
                obj->set("endname",me);
                tell_object(me,HIY"��õ�һ�����⽱����\n"NOR);
        me->delete("�ɺ��⴫");
        me->delete("Ц������");
        me->delete("ѩɽ�ɺ�"); 
        me->delete("�齣����¼");
        me->delete("���Ǿ�");
        me->delete("�������");
        me->delete("�����˲�");
        me->delete("������");
        me->delete("���Ӣ�۴�");
        me->delete("����������");
        me->delete("����Х����");
        me->delete("��Ѫ��");
        me->delete("¹����");
        me->delete("ԧ�쵶"); 
        me->set_temp("bigreward",1);
                }
}
int help(object me)
{
  this_player()->start_more(@HELP
�������������ָ�ʽ��tianshu ��tianshu begin ��tianshu select 
���ָ�dating ������renwu ����jiaochai ���status ״̬
����ϸ��ʹ�ü�������������Ĺ��̣�
> ask nanxian about tianshu
�������ʹ����йء�tianshu������Ϣ��
����˵�������������飿����selectѡ������Ҫ�ҵ����飬Ȼ��(accept)
> select

                �����ɣ���ѩ�����������죴���䣵���ף�����¹
                ����Ц�����飹����ᣮ���⣮�У㣮�̣��䣮ԧ
                
��ѡ��0��1��2��3����������1
�������ʼ��ѩɽ�ɺ��ˡ�
> accept
����˵�������Ѿ������ѩɽ�ɺ�������select��ѡ����begin�ؿ���
> begin
�㿪ʼ����ѩɽ�ɺ��ˣ�
> accept
����˵����Ŀǰ�ƺ���ǧ���Ƕ���Щ������
> dating
��ǧ��˵������֪��ѩɽ�ɺ����Ķ����������ɼ����������ٸ����㡣
> renwu
��ǧ��˵��������Ҫ�Ը��ң����������ﱣ���ң�
> ���������˽���������ؿ�����ǧ����
�����˶���ǧ���ȵ�������������ã�ԭ����������ȥ���ɣ�
���������ˡ�
> jiaochai
��ǧ��˵�����ܺã����Ѿ��������ҡ�
�㱻�����ˣ�
��ʮ��ʵս����
�˵�Ǳ��
��ȥ���������ʣ�������û��ʲô��Ϣ��
> dating
����˵������֪��ѩɽ�ɺ����Ķ����������ɼ����������ٸ����㡣
> renwu
����˵����������ҵ�������
> jiaochai
����˵�����ܺã����Ѿ������ҵ������ˡ�
�㱻�����ˣ�
��ʮ��ʵս����

�˵�Ǳ��
��ȥ���������ʣ�������û��ʲô��Ϣ��
> dating
����˵������֪��ѩɽ�ɺ����Ķ����������ɼ����������ٸ����㡣
> renwu
����˵���������ɱ�˻��ɣ�����ʬ�������ң�
...
�������ˡ�
> get corpse
�㽫���ɵ�ʬ������������ڱ��ϡ�
> jiaochai
����˵�����ܺã����Ѿ�����ɱ�˻��ɡ�
�㱻�����ˣ�
��ʮ��ʵս����
�˵�Ǳ��
��ȥ���������ʣ�������û��ʲô��Ϣ��
......
С����˵�����ܺã����Ѿ��������ҡ�
�㱻�����ˣ�
��ʮ��ʵս����
�˵�Ǳ��
С����˵�����������һ�����飬����������ã���͸���ɡ�
�㱻�����ˣ�
��ǧ�߰���ʮһ��ʵս����
���ٶ�ʮ����Ǳ��
��ʮ��������
> l book
��ѩɽ�ɺ���--һ�������Ѿõ��飬��Ϊ����������
> give book to nanxian
��������Ц��Ц��
����˵������л��λ���������һ�����кñ��ģ�
�㱻�����ˣ�
��ǧ�߰���ʮ�ĵ�ʵս����
�߰پ�ʮ��Ǳ��
ʮ��������
���ó�����(Book)�����͡�
> status

�� ����Ӣ�� ���컨����ӡ���Ҫ���ң���ʲô����֪��������������(Diliu)
 �ɺ��⴫��     δ���          Ц��������      δ���
 ѩɽ�ɺ���     �����          �齣����¼��    δ���
 ���Ǿ���       �����          ������£�      δ���
 �����˲���     �����          �����У�        δ���
 ���Ӣ�۴���   δ���          ���������ǣ�    δ���
 ����Х���磺   δ���          ��Ѫ����        �����
 ¹���ǣ�       �����          ԧ�쵶��        δ���
���Բ鿴���Ѿ���ɵ���������״��
> tianshu
�����ڸ�����ѩɽ�ɺ���
> begin
�㿪ʼ����ѩɽ�ɺ��ˣ�
> tianshu
��Ŀǰ�����ѩɽ�ɺ���
> ask nanxian about tianshu
�������ʹ����йء�tianshu������Ϣ��
����˵�������������飿����selectѡ������Ҫ�ҵ����飬Ȼ��(accept)
��ȥ�����ʹ���
HELP
    );
    return 1;
}
