// guilei.c
// by Smallfish

#include <ansi.h>

inherit F_CLEAN_UP;

int guilei_dir(object me, string dir, string type, int continueable, int *total);
int guilei_file(object me, string file, string type);
static int all_num;	//�ж϶����ļ�������

int main(object me, string arg)
{
        string dir,type,type_name;
        int continueable;
        int *total = ({0});

        seteuid(geteuid(me));

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        write("�ļ����ࡣ");

        continueable = 1;
 	if (!arg || !(sscanf(arg,"%s %s",dir,type) == 2)) 
                return notify_fail("��ʽ��guilei <·��> room|npc \n");

       	dir = resolve_path(me->query("cwd"), dir);

        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

	if (file_size(dir) != -2)
		return notify_fail("û��" + dir + "���·����\n");

        //��������
        switch(type)
        {
                case "room":
                        type_name = "����";
                        break;
                case "npc":
                        type_name = "NPC";
                        break;
                case "obj":
                        type_name = "��Ʒ";
                        break;
                default:
                        return notify_fail("��ʽ��guilei <·��> room|npc \n");
        }

	me->set("cwd", dir);

	message_system("�������" + type_name + "�����У����Ժ�...");
        if (! guilei_dir(me, dir, type, continueable, total))
        {
                write(HIR "��������������ֹ��\n" NOR);
        }

        if (total[0] > 0)
        {
                write(HIC "�ܹ���" + HIW + total[0] + HIC "���������ɹ����࣡\n" NOR);
                write(HIC "������Ϣ�����" + HIW + "/log/static/" + type + HIC "֮�У�\n" NOR);
        } else
                write(HIC "û�й����κε�����\n" NOR);

        return 1;
}

int guilei_dir(object me, string dir, string type, int continueable, int *total)
{
	int i;
        int l;
        int filecount, compcount;
        mixed *file;
        string filename;

        if (! is_root(previous_object()))
                return 0;

	file = get_dir(dir, -1);
	if (! sizeof(file))
	{
                if (file_size(dir) == -2)
                        write(dir + "���Ŀ¼�ǿյġ�\n");
		else
		        write("û��" + dir + "���Ŀ¼��\n");
                return 1;
	}

        write (HIY "��ʼ���Ŀ¼" + dir + "����������ļ���\n" NOR);
	i = sizeof(file);
        compcount = 0;
        filecount = 0;
        all_num = 0;
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] != -2)
                {
                        filecount++;
                        filename = file[i][0];
                        l = strlen(filename);
                        if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                                continue;

                        if (! guilei_file(me, dir + filename, type) &&
                            ! continueable)
                                return 0;

                        compcount++;
                        total[0]++;
                        if ((compcount % 70) == 0)
                                write("\n");
                }

                // continue to compile next file
	}
        write(HIC "\n������Ŀ¼" + dir + "�µ�" + HIW + filecount + HIC +
              "���ļ���\n���������" + HIW + compcount + HIC + 
              "��������\n����������" + HIW + all_num + HIC + "��������\n" + NOR );

	i = sizeof(file);
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] == -2)
                {
                        file[i][0] += "/";
                        write("\n");
                        if (! guilei_dir(me, dir + file[i][0], type, continueable, total) &&
                            ! continueable)
                                return 0;
                }
        }
	return 1;
}

int guilei_file(object me, string file, string type)
{
        string document;
        mapping all_obj;
        string *ob_list,the_id,the_name,the_object,file_name;
        int i,is_ok;
        object obj,*inv;

        if (file == "/cmds/adm/guilei.c")
                // �����Ҷ���ָ���ļ�
                return 1;

        write (".");
        
        //���෿���ļ�
        if (type == "room")
        {
                document = read_file(file);
                if (! document) return 0;
                is_ok = strsrch(document, "inherit ROOM", 1);
                
                if (is_ok >= 0)
                {
                        all_num ++;
                        file_name = file->query("short");
                        all_obj = file->query("objects");

                        if (! mapp(all_obj))
                        {
                                file->set("objects", ([
                	                "/u/vin/no_npc" : 1,
                                ]));
                        }

                        if (! mapp(all_obj))
                                return 0;

                        ob_list = keys(all_obj);

                        for (i = 0; i < sizeof(ob_list); i++)
                        {
                                reset_eval_cost();
                                the_object = ob_list[i] + ".c";
                                the_name = the_object->name(1);
                                the_id = the_object->query("id");
                                log_file("static/room", sprintf("%s|%s|%s|%s|%s\n",
                                        file, 
                                        file_name, 
                                        the_object, 
                                        the_name, 
                                        the_id,
                                ));
                        }
                }
        }

        //����NPC�ļ�
        if (type == "npc"){
                document = read_file(file);
                if (!document) return 0;
                is_ok = strsrch(document,"inherit NPC",1);
                
                if (is_ok > 0) {
                        all_num ++;
                        obj = new(file);
                        if (!obj) return 0;
                        log_file("static/npc", sprintf("%s|%s|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%s|%s|%s\n",
                                file,
                                obj->query("id"),
                                obj->query("name"),
                                obj->query("combat_exp"),
                                obj->query("jing"),
                                obj->query("eff_jing"),
                                obj->query("qi"),
                                obj->query("eff_qi"),
                                obj->query("jingli"),
                                obj->query("max_jingli"),
                                obj->query("neili"),
                                obj->query("max_neili"),
                                obj->query("shen"),
                                obj->query("gender"),
                                obj->query("race"),
                                obj->query("family/family_name")
                        ));

                        inv = all_inventory(obj);
                        if (sizeof(inv)) {
                                for (i = 0; i < sizeof(inv); i++)
                                {
                                        log_file("static/npc_obj", sprintf("%s|%s.c|%s|%s\n",
                                                file, 
                                                base_name(inv[i]),
                                                inv[i]->query("id"),
                                                inv[i]->name(1)
                                        ));
                                }
                        }

                        all_obj = obj->query("vendor_goods");
                        if (!mapp(all_obj)) return 0;
                        ob_list = keys(all_obj);
                        for (i = 0; i < sizeof(ob_list); i++) {
                                the_object = ob_list[i] + ".c";
                                log_file("static/npc_obj", sprintf("%s|%s|%s|%s\n",
                                        file, 
                                        the_object,
                                        the_object->query("id"), 
                                        the_object->name(1)
                                ));
                        }
                        destruct(obj);
                }
        }

        //������Ʒ�ļ�
        if (type == "obj"){
                document = read_file(file);
                if (!document) return 0;
                is_ok = strsrch(document,"inherit NPC",1);
                if (is_ok > 0) return 0;
                is_ok = strsrch(document,"inherit ROOM",1);
                if (is_ok > 0) return 0;
                obj = new(file);
                if (!obj) return 0;
                all_num ++;
                log_file("static/obj", sprintf("%s|%s|%s|%d|%d\n",
                        file,
                        obj->query("id"),
                        obj->query("name"),
                        obj->query("value"),
                        obj->query_weight()
                ));
                destruct(obj);
        }
        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: guilei <·��|�ļ���> <room|npc|obj>
 
���ָ������ָ����һ���ļ�����һ��Ŀ¼�µķ��䡢�����Ʒ��
���Խ��й��ࡣ
room������ʾ���෿���ļ�����Ϣ�����ļ����������������������
Ʒ�ļ�������Ʒ����������ƷӢ������
npc ������ʾ���������ļ�����Ϣ�����ļ�������������Ӣ��������
��ID��������������������Ʒ���ļ�������ƷID����Ʒ������������
�ĸ���HP���ԡ��������ҪSCORE���ԣ�
obj ������ʾ������Ʒ�ļ�����Ϣ�����ļ�������ƷID����Ʒ��������
��Ʒ�ļ�ֵ�ȵȣ�

������Ϣ�����/log/staticĿ¼�¡�

HELP );
        return 1;
}
