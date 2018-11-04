// mudlist.c

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <net/dns.h>
#include <mudlib.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
        string name;
        string mudn;
        string vis_mudn;
	int loop, size;
        string local_mudlib;
        int uc;

	if (! find_object(DNS_MASTER))
		return notify_fail("���羫�鲢û�б����룬���Ƚ���·�������롣\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if (! mud_list)
		return notify_fail(LOCAL_MUD_NAME() + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

	// Get list of all mud names within name server
	muds = keys(mud_list) - ({ "DEFAULT" });

        if (! arg)
        {
                // filter for release sub sites & me
                local_mudlib = MUDLIB_NAME;
                muds = filter_array(muds, (: $(mud_list)[$1]["MUDLIB"] == $(local_mudlib) &&
                                             (! VERSION_D->is_release_server() ||
                                              $1 == INTERMUD_MUD_NAME ||
                                              CONFIG_D->query($(mud_list)[$1]["HOSTADDRESS"]) == "valid") :));
        } else
        if (arg == "sites")
        {
                // filter for all sub sites & me
                local_mudlib = MUDLIB_NAME;
                muds = filter_array(muds, (: $(mud_list)[$1]["MUDLIB"] == $(local_mudlib) &&
                                             (! VERSION_D->is_release_server() ||
                                              $1 == INTERMUD_MUD_NAME ||
                                              CONFIG_D->query($(mud_list)[$1]["HOSTADDRESS"])) :));
        } else
        if (arg != "all")
                // filter for muds matched argument
                muds = filter_array(muds, (: sscanf($1, $(arg) + "%*s") :));

        if (! sizeof(muds))
                return notify_fail("Ŀǰ��վ��û�к���� MUD ȡ���κ���ϵ��\n");

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	output = WHT BBLU " Mud          ��������            ������·λַ     �˿�  ���� \n" NOR
                 "��������������������������������������������������������������\n";

        //      Count for users
        uc = 0;

	//	Loop through mud list and store one by one
	for (loop = 0, size = sizeof(muds); loop < size; loop++)
        {
                mudn = muds[loop];
                if (undefinedp(mud_list[mudn]["USERS"]))
                        continue;

                if (! stringp(name = mud_list[mudn]["MUDNAME"]))
                        name = "δ֪����";

		// filter some ... strange ansi
		name = replace_string(name, ESC "[0;37;0m", "");
		name = replace_string(name, ESC "[2;17m", "");
                name = filter_color(name);

                // ��������
                vis_mudn = filter_color(mudn);
                if (strlen(vis_mudn) > 12) vis_mudn = vis_mudn[0..11];
                if (strlen(name) > 20) name = name[0..19];

                if (mudn == mud_nname())
                        output += HIY BRED;

                if (stringp(mud_list[mudn]["ZONE"]))
                        name += "(" + mud_list[mudn]["ZONE"] + ")";

		output += sprintf(" %-13s%-20s%-17s%-6s%-4s \n" NOR,
				  upper_case(vis_mudn), name,
			          mud_list[mudn]["HOSTADDRESS"],
			          mud_list[mudn]["PORT"],
                                  mud_list[mudn][DNS_NO_CONTACT] > MAX_RETRYS ? "ʧȥ��ϵ"
                                                                              : mud_list[mudn]["USERS"]);

                // �ۼ��������
                if (mud_list[mudn][DNS_NO_CONTACT] <= MAX_RETRYS)
                        uc += atoi(mud_list[mudn]["USERS"]);
        }
        output += "��������������������������������������������������������������\n";

        if (! arg || arg == "sites")
                output += "����̶���� " CYN + uc + NOR " λ�������Ϸ�С�\n";

        if (objectp(me))
	        me->start_more(output);
        else
                write(output + "\n");

	return 1;
}

int help()
{
	write(@HELP
ָ���ʽ : mudlist <MUD����> | all | sites

���ָ�������г�Ŀǰ����� Mud ȡ����ϵ�е����� Mud��

������Ӳ������г��� Mud ������ʽ��վ��
ʹ�� all ������ʾ�г����е� Mud ��Ϸ��
ʹ�� sites ������ʾ�г��� Mud �����з�վ��
����������ϲ��������г��� <MUD����> ��ͷ��վ�㡣
HELP );
	return 1;
}
