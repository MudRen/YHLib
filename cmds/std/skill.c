// skill.c
// edit by smallfish
// Updated by vin for heros.cn

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

string *valid_types = ({
        "force",
        "dodge",
        "unarmed",
        "cuff",
        "strike",
        "finger",
        "hand",
        "claw",
        "sword",
        "blade",
        "staff",
        "hammer",
        "club",
        "whip",
        "dagger",
        "throwing",
        "parry",
        "magic",
        "medical",
        "poison",
        "chuixiao-jifa",
        "tanqin-jifa",
        "guzheng-jifa",
        "cooking",
});

int main(object me, string arg)
{
        string file, dir, filename;
        string msg, msg1;
        int i, j, l, is_force;
        mixed *all_file;

        seteuid(getuid());

        if (! arg)
                return notify_fail("ָ���ʽ��skill  <��������> | <����������>\n");

        if (! stringp(file = SKILL_D(arg)) || file_size(file + ".c") <= 0)
        {
                // Ӣ�ĵ��Ҳ������Ǿ���������
                if (! stringp(arg = CHINESE_D->find_skill(arg)))
                        return notify_fail("û�����ּ��ܴ��ڡ�\n");

                // �����������ҵ���Ӣ�����������Ƿ�����д˼���
                if (! stringp(file = SKILL_D(arg)) || file_size(file + ".c") <= 0)
                        return notify_fail("û�����ּ��ܴ��ڡ�\n");
        }

        msg = "����" + to_chinese(arg) + "����ϸ�������£�\n";
        msg += HIC "��" HIY "������������������������������������"
               "��������" HIC "��\n" NOR;
        msg += WHT + "  �书���ƣ�  " HIG + arg + "\n" + NOR;
        msg += WHT + "  �������ƣ�  " HIG + to_chinese(arg) + "\n" + NOR;

        is_force = 0;

        if (SKILL_D(arg)->valid_enable("force"))
                is_force = 1;

        if (member_array(arg, valid_types) != -1)
        {
                msg += WHT "  �书������  " HIG "�����书\n" NOR;
                msg += HIC "��" HIY "����������������������������"
                       "����������������" HIC "��\n" NOR;
                write(msg);
                return 1;
        }

        if (! wizardp(me) && me->query_skill(arg) <= 0)
        {
                msg += HIC "��" HIY "����������������������������"
                       "����������������" HIC "��\n" NOR;
                write(msg);
                return 1;
        }

        // ��ѯ�书�� pfm ���
        msg1 = "";
        j = 0;
        dir = file;

        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

        if (is_force)
                dir += "perform/";

        if (file_size(dir) != -2)
                msg1 += "";
        else
        {
                all_file = get_dir(dir);
                if (! sizeof(all_file))
                        msg1 += "";
                else
                {
                        for (i = 0; i < sizeof(all_file); i++)
                        {
                                filename = all_file[i];
                                l = strlen(filename);
                                if (filename[l - 1] == 'c' && filename[l - 2] == '.')
                                {
                                        j++;
                                        msg1 += sprintf(HIY "%s  " NOR, filename[0..l-3]);
                                }
                        }

                        if (msg1 != "")
                        {
                                msg += WHT "  �书���У�  " NOR;
                                msg += msg1;
                                msg += "\n";
                        }
                }
        }

        // ��ѯ�ڹ��� exert ���
        if (! is_force)
        {
                msg += HIC "��" HIY "����������������������������"
                       "����������������" HIC "��\n" NOR;
                write(msg);
                return 1;
        }

        msg1 = "";
        j = 0;

        dir = file;

        if (dir[strlen(dir) - 1] != '/')
                dir += "/";
 
        if (file_size(dir + "exert/") == -2)
                all_file = get_dir(dir + "exert/");
        else
        if (file_size(dir) == -2)
                all_file = get_dir(dir);
        else
        {
                msg += HIC "��" HIY "����������������������������"
                       "����������������" HIC "��\n" NOR;
                write(msg);
                return 1;
        }

        if (! sizeof(all_file))
        {
                write(msg);
                return 1;
        }

        for (i = 0; i < sizeof(all_file); i++)
        {
                filename = all_file[i];
                l = strlen(filename);
                if (filename[l - 1] == 'c' && filename[l - 2] == '.')
                {
                        j++;
                        msg1 += sprintf(HIW "%s  " NOR, filename[0..l-3]);
                }
        }

        if (msg1 != "")
        {
                msg += WHT "  �ڹ����ܣ�  " NOR;
                msg += msg1;
                msg += "\n";
        }

        msg += HIC "��" HIY "������������������������������������"
               "��������" HIC "��\n" NOR;
        write(msg);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��skill  <��������> | <����������>

���ָ��������ָ����ĳ���书���ܣ��������ƿ�������
����������㱾��߱�����ܣ������ʾ���ü��ܵľ��м�
���⹦�ܡ�

���ָ�skills

HELP);
        return 1;
}
